#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
typedef struct node *NODE;
NODE getnode()
{
NODE p;
p=(NODE) malloc(sizeof(struct node));
if(p!=NULL)
{
return p;
}
else
{
printf("Memory could not be allocated\n");
return NULL;
}
}
NODE insert(int item,NODE head)
{
NODE p;
p=getnode();
p->data=item;
p->next=head;
head=p;
return head;
}
NODE sort(NODE head)
{
NODE p=head,q=NULL,r=NULL;
int temp;
if(head==NULL)
{
printf("List is empty,can't perform sortimng\n");
return head;
}
while(p->next!=NULL)
{
	q=p->next;
	while(q!=NULL)
	{
		if(p->data>q->data)
		{
			temp=p->data;
			p->data=q->data;
			q->data=temp;
		}
		if(p->data==q->data)
		{
			r=q;
			printf("Deleted element=%d\n",q->data);
			p->next=q->next;
			q=q->next;
			free(r);
		}
		q=q->next;
	}
	p=p->next;
}
return head;
}
NODE del(NODE head)
{
NODE p=head;
if(head==NULL)
{
printf("List is empty,deletion not possible\n");
return head;
}
printf("Deleted element=%d\n",p->data);
head=p->next;
free(p);
return head;
}
void disp(NODE head)
{
NODE p=head;
if(head==NULL)
{
printf("List is empty\n");
return;
}
while(p!=NULL)
{
printf("%d\n",p->data);
p=p->next;
}
}

int main()
{
NODE head=NULL;
int e,ch,j=1;
clrscr();
while(j!=0)
{
	printf("Enter the choice\n");
	printf("1.insert\t2.delete\t3.sort\t4.display\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		printf("Enter the item to be inserted\n");
		scanf("%d",&e);
		head=insert(e,head);
		break;
		case 2:
		head=del(head);
		break;
		case 3:
		head=sort(head);
		break;
		case 4:
		printf("***********\n");
		disp(head);
		break;
		default:
		printf("Invalid\n");
		exit(0);
		break;
	}
	printf("Enter other than '0' to continue\n");
	scanf("%d",&j);
}
getch();
return 0;
}