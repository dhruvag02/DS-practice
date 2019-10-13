#include<stdio.h>
#include<conio.h>
#define S 5
void push(int item,int s[S],int *top);
int pop(int s[S],int *top);
void disp(int s[S],int *top);
int main()
{
int s[S],st[S];
int top1=-1,top2=-1;
int e,i,n,count=0,small;
clrscr();
printf("Enter the number of values to be pushed\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter the value to be pushed\n");
scanf("%d",&e);
push(e,s,&top1);
}
printf("******\n");
disp(s,&top1);
small=s[0];
for(i=0;i<n;i++)
{
if(s[i]<small)
small=s[i];
}
for(i=0;i<n;i++)
{
if(s[i]==small)
count++;
}
for(i=0;i<count;i++)
{
push(small,st,&top2);
}
for(i=0;i<n;i++)
{
if(s[i]!=small)
push(s[i],st,&top2);
}
printf("*******\n");
disp(st,&top2);
getch();
return 0;
}
void push(int item,int s[S],int *top)
{
if(*top==S-1)
{printf("Stack overflow\n");
return;}
*top=*top+1;
s[*top]=item;
}
void disp(int s[S],int *top)
{
int i;
if(*top==-1)
{
printf("Stack is empty\n");
return;}
for(i=*top;i>=0;i--)
{
printf("%d\n",s[i]);
}
}