#include<stdio.h>
#include<stdlib.h>
#define stacksize 50
#include<string.h>
int input_precedence(char symbol)
{
    switch(symbol)
    {
        case '+':
        case '-':return 1;
        case '*':
        case '/':return 3;
        case '^':
        case '$':return 6;
        case '(':return 9;
        case ')':return 0;
        default: return 7;
    }
}
int stack_precedence(char symbol)
{
    switch (symbol)
    {
        case '+':
        case '-':return 2;
        case '*':
        case '/':return 4;
        case '^':
        case '$':return 5;
        case '(':return 0;
        case '#':return -1;
        default:return 8; 
    }
}
void push(char item,int *top, char s[])
{
    if(*top==stacksize-1)
    {
        printf("Stack overflow\n");
        return;
    }
    *top+=1;
    s[*top]=item;
}
char pop(int *top,char s[]){
    char item;
    if(*top==-1)
    {
        return -1;
    }
    item=s[*top];
    *top-=1;
    return item;
}
void infix_conversion(char infix[],char postfix[])
{
    int j,top,i,n;
    char symbol,s[100];
    j=0;
    top=-1;
    push('#',&top,s);
    n=strlen(infix);
    for(i=0;i<n;i++)
    {
        symbol=infix[i];
        while(stack_precedence(s[top])>input_precedence(symbol))
        {
            postfix[j]=pop(&top,s);
            j++;
        }
        if(stack_precedence(s[top])!=input_precedence(symbol))
        {
            push(symbol,&top,s);
        }
        else
        {
            pop(&top,s);
        }
    }
    while(s[top]!='#')
    {
        postfix[j]=pop(&top,s);
        j++;
    }
    postfix[j]='\0';
}
void main()
{
    char infix[50],postfix[50];
    printf("Enter the infix expression:");
    scanf("%s",infix);
    infix_conversion(infix,postfix);
    printf("The postfix expression is : %s",postfix);
}