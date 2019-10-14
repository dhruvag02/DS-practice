#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
char string[20];
struct node *next;
};
typedef struct node *NODE;
NODE getnode();
NODE insert(char item[20],NODE head);
NODE del(NODE head,char value[20]);
void disp(NODE head);
int main()
{
NODE head=NULL;
char item[20],value[20];
int ch,j=1;
clrscr();
while(j!=0)
{
printf("Enter choice\n");
printf("1.Insert\t2.Delete Value\t3.Display\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("Enter the string to be inserted\n");
scanf("%s",item);
head=insert(item,head);
break;
case 2:
printf("Enter string to be deleted\n");
scanf("%s",value);
head=del(head,value);
break;
case 3:
printf("********\n");
disp(head);
break;
default:
printf("Invalid option\n");
exit(0);
break;
}
printf("Enter other than '0' to continue\n");
scanf("%d",&j);
}
getch();
return 0;
}
NODE insert(char item[20],NODE head)
{
NODE p;
p=getnode();
strcpy(p->string,item);
printf("Inserted string=%s\n",p->string);
p->next=head;
head=p;
return head;
}
NODE getnode()
{
NODE p;
p=(NODE) malloc(sizeof(struct node));
if(p!=NULL)
return p;
else
{printf("Memory could not be allocated\n");
return NULL;}
}

NODE del(NODE head,char value[20])
{
NODE curr=head,prev=NULL;
if(head==NULL)
{printf("List is empty\n");
return head;}
else if(head->next==NULL)
{
if(strcmp(head->string,value)==0)
{
free(head);
return NULL;
}
else
{printf("Value not found\n");
return head;}
}
else
{
while(curr!=NULL)
{
if(strcmp(curr->string,value)==0)
{
if(prev==NULL)
{
head=curr->next;
free(curr);
}
else
{
prev->next=curr->next;
free(curr);
}
return head;
}
prev=curr;
curr=curr->next;
}
}
if(curr==NULL)
{printf("String does not match\n");
return head;
}
}
void disp(NODE head)
{
NODE p=head;
if(head==NULL)
{printf("List is empty\n");
return;}
while(p!=NULL)
{
printf("%s\n",p->string);
p=p->next;
}
}