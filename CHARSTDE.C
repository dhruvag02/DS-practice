#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 5
void push(char str[80],char stack[MAX][80],int *top)
{
if(*top== MAX-1)
{printf("Stack overflow\n");
return;}
*top=*top+1;
strcpy(stack[*top],str);
printf("%s\t is pushed\n",stack[*top]);
}
void pop(char str[80],char stack[MAX][80],int *top)
{
if(*top==-1)
{printf("Stack underflow\n");
return;}
strcpy(str,stack[*top]);
printf("%s is popped\n",str);
*top=*top-1;
return;
}
void disp(char stack[MAX][80],int *top)
{
int i;
if(*top==-1)
{printf("Stack is empty\n");
return;}
for(i=*top;i>=0;i--)
{
printf("%s\n",stack[i]);
}
}
int main()
{
char stack[MAX][80],str[80];
int ch=0,top=-1,j=1;
clrscr();
while(j!=0)
{
printf("Enter choice\n");
printf("1.PUSH\t2.POP\t3.Display\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("Enter string to be pushed\n");
scanf("%s",str);
push(str,stack,&top);
break;
case 2:
pop(str,stack,&top);
break;
case 3:
disp(stack,&top);
break;
default:
printf("Invalid option\n");
break;
}
printf("Enter other than '0' to continue\n");
scanf("%d",&j);
}
getch();
return 0;
}