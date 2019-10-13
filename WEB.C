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
return p;
else
{
printf("Memory could not be allocated\n");
return NULL;
}
}
NODE insert(int item,NODE head)
{
NODE p,q;
q=getnode();
q->data=item;
q->next=NULL;
if(head==NULL)
{
return q;
}
else
{
p=head;
while(p->next!=NULL)
{
p=p->next;
}
p->next=q;
return head;
}
}
NODE webp(int x,NODE head)
{
NODE curr=head;
int count=1;
if(head==NULL)
{
printf("List is empty,NO links cliscked\n");
return head;
}
if(head->next==NULL)
{
	if(count==x)
	{
		printf("Webpage searched=%d,after %d clicks\n",head->data,x);
	}
	else
	{
		printf("NOT so many clicks done\n");
	}
return head;
}
else
{
	while(curr!=NULL&&count!=x)
	{
		curr=curr->next;
		count++;
	}
	if(count==x)
	{
		printf("searched webpage=%d, after %d clicks\n",curr->data,x);
	}
	else
	{
	printf("NOT so many clicks done\n");
	}
return head;
}
}
void disp(int x,NODE head)
{
NODE p=head;
if(head==NULL)
{
	printf("List is empty,no links clicked\n");
	return;
}
else
{
	while(p!=NULL)
	{
		printf("Webpage visited=%d,after %d clicks\n",p->data,x);
		p=p->next;
		x++;
	}
}
}
int main()
{
NODE head=NULL;
int n,x;
int ch,j=1,i;
clrscr();
printf("Enter the total number of clicks or total number of linked webpages visited\n");
scanf("%d",&n);
for(i=1;i<n+1;i++)
{
head=insert(i,head);
}
while(j!=0)
{
	printf("Enter the number of clicks determining the page to be visited\n");
	scanf("%d",&x);
	printf("Enter the choice\n");
	printf("1.Display page after %d clicks\t2.Display total number of pages\n",x);
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		head=webp(x,head);
		break;
		case 2:
		printf("**********\n");
		i=1;
		disp(i,head);
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