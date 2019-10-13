#include<stdio.h>
#include<conio.h>
#define S 100
void push(int item,int st[S],int *top,int max);
int pop(int st[S],int *top,int min);
void disp(int st[S],int *top,int min);
int main()
{
int st[S];
int e1,x1,e2,x2,top1=-1,top2=49,ch;
clrscr();
while(ch!=-1)
{
printf("Enter choice\n");
printf("1.push stack1\tpush stack2\t3.pop stack1\4.tpopstack2\t5.display stack1\t6.display stack2\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("Enter element to be pushed to stack1\n");
scanf("%d",&e1);
push(e1,st,&top1,50);
break;
case 2:
printf("Enter element to be pushed to stack2\n");
scanf("%d",&e2);
push(e2,st,&top2,100);
break;
case 3:
printf("You entered pop from stack1\n");
x1=pop(st,&top1,-1);
printf("Popped element=%d\n",x1);
break;
case 4:
printf("You entered pop from stack2\n");
x2=pop(st,&top2,49);
printf("Popped element=%d\n",x2);
break;
case 5:
printf("*********\nDisplay from stack1\n*******\n");
disp(st,&top1,-1);
break;
case 6:
printf("********\nDisplay from stack2\n*********\n");
disp(st,&top2,49);
break;
default:
printf("Invalid option\n");
break;
}
printf("Enter other than '-1' to continue\n");
scanf("%d",&ch);
}
getch();
return 0;
}
void push(int item,int st[S],int *top,int max)
{
if(*top==max-1)
{printf("Stack overflow\n");
return;}
*top=*top+1;
st[*top]=item;
}
int pop(int st[S],int *top,int min)
{
int v;
if(*top==min)
{printf("Stack underflow\n");
return -9999;}
v=st[*top];
*top=*top-1;
return v;
}
void disp(int st[S],int *top,int min)
{
int i;
if(*top==min)
{printf("Stack is empty\n");
return;}
for(i=*top;i>=min+1;i--)
{printf("%d\n",st[i]);}
}