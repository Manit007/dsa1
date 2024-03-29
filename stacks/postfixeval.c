#include<stdio.h>
#include<process.h>
#include<string.h>
#include<math.h>
#define stacksize 50
void push(int item,int *top, int s[])
{
    if(*top==stacksize-1)
    {
        printf("Stack overflow\n");
        return;
    }
    *top+=1;
    s[*top]=item;
}
int pop(int *top,int s[])
{
    int item;
    if(*top==-1)
    {
        return -1;
    }
    item=s[*top];
    *top-=1;
    return item;
}
int evaluate(char postfix[])
{
    int top,n,i,op1,op2,res,s[100];
    char symbol;
    top=-1;
    n=strlen(postfix);
    for (i = 0; i < n; i++)
    {
        symbol=postfix[i];
        switch(symbol)
        {
            case '+':op2=pop(&top,s);
                     op1=pop(&top,s);
                     res=op1+op2;
                     push(res,&top,s);
                     break;
            case '-':op2=pop(&top,s);
                     op1=pop(&top,s);
                     res=op1-op2;
                     push(res,&top,s);
                     break;
            case '*':op2=pop(&top,s);
                     op1=pop(&top,s);
                     res=op1*op2;
                     push(res,&top,s);
                     break;
            case '/':op2=pop(&top,s);
                     op1=pop(&top,s);
                     res=op1/op2;
                     push(res,&top,s);
                     break;
            case '^':op2=pop(&top,s);
                     op1=pop(&top,s);
                     res=(int)pow((double)op1,(double)op2);
                     push(res,&top,s);
            default: push(symbol-'0',&top,s);
            break;
        }
    }
    return(pop(&top,s));
}
void main(){
    int res;
    char postfix[50];
    printf("Enter the postfix expression:");
    scanf("%s",postfix);
    res=evaluate(postfix);
    printf("Solution of the postfix expression is %d",res);
}