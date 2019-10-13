#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define S 5
struct Stack
{
char usn[S][80];
char name[S][80];
char mb_no[S][80];
int top;
};
void push(char u[80],char n[80],char no[80],struct Stack *st);
void display(struct Stack *st);
void pop(struct Stack *st);

int main()
{
char u[80],n[80],no[80];
int i,num;
struct Stack st;
st.top=-1;
clrscr();
printf("Enter the number of students\n");
scanf("%d",&num);
for(i=0;i<num;i++)
{
printf("Enter USN of student\n");
scanf("%s",u);
printf("Enter name of student\n");
scanf("%s",n);
printf("Enter mobile number of student\n");
scanf("%s",no);
push(u,n,no,&st);
}
display(&st);
pop(&st);
getch();
return 0;
}

void push(char u[80],char n[80],char no[80],struct Stack *st)
{
if(st->top==S-1)
{printf("Stack overflow\n");
return;}
st->top=st->top+1;
strcpy(st->usn[st->top],u);
printf("%s is pushed\n",st->usn[st->top]);
strcpy(st->name[st->top],n);
printf("%s is pushed\n",st->name[st->top]);
strcpy(st->mb_no[st->top],no);
printf("%s is pushed\n",st->mb_no[st->top]);
}

void display(struct Stack *st)
{
int i;
if(st->top==-1)
{printf("Stack is empty\n");
return;}
for(i=st->top;i>=0;i--)
{
printf("%s\t%s\t%s\n",st->usn[i],st->name[i],st->mb_no[i]);
}
}
void pop(struct Stack *st)
{
char data1[80];
char data2[80];
char data3[80];
if(st->top==-1)
{printf("Stack underflow\n");
return;}
strcpy(data1,st->usn[st->top]);
printf("Deleted usn=%s\t",data1);
strcpy(data2,st->name[st->top]);
printf("Deleted name=%s\t",data2);
strcpy(data3,st->mb_no[st->top]);
printf("Deleted no=%s\n",data3);
st->top=st->top-1;
}