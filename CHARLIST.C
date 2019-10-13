#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define S 20
struct node
{
char str[S];
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
{printf("Memory could not be alloctaed\n");
return NULL;}
}
NODE insert(char data[S],NODE head)
{
NODE p;
p=getnode();
strcpy(p->str,data);
printf("%s\t is inserted\n",p->str);
p->next=head;
head=p;
return head;
}
NODE del(NODE head)
{
NODE p=head;
if(head==NULL)
{printf("List is empty\n");
return head;}
printf("%s\t is deleted\n",p->str);
head=p->next;
free(p);
return head;
}
void disp(NODE head)
{
NODE p=head;
if(head==NULL)
{printf("List is empty\n");
return;}
while(p!=NULL)
{
printf("%s\n",p->str);
p=p->next;
}
}
int main()
{
NODE head=NULL;
char s[S];
int j=1,ch;
clrscr();
while(j!=0)
{
printf("Enter choice\n");
printf("1.Insert\2.Delete\t3.Display\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("Enter string to be inserted\n");
scanf("%s",s);
head=insert(s,head);
break;
case 2:
head=del(head);
break;
case 3:
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