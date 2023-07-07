#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
#define TRUE 1
#define FALSE 0
typedef struct{
    char items[MAX];
    int tos; // top of stack
    
}stack;

int IsEmpty(stack *sp)
{
    if(sp->tos==-1)
    return TRUE;
    else
    return FALSE;
}

int IsFull(stack *sp)
{
    if(sp->tos==MAX-1)
    return TRUE;
    else
    return FALSE;
}

void pop(stack*sp)
{
    if(IsEmpty(sp))
    {
        printf("stack underflow.");
        exit(0);
    }
    sp->tos--;
}
void push(stack*sp,char ch)
{
    if(IsFull(sp))
    {
        printf("stack oveflow.");
        exit(0);
    }
    sp->items[++sp->tos]=ch;
}
char peek(stack*sp)
{
    if(IsEmpty(sp))
    return '\0';
    else
    return sp->items[sp->tos];
}
int main()
{
    stack s;
    int i,valid=TRUE,ch;
    char exp[MAX];
    s.tos=-1;
    printf("enter your expression:");
    scanf("%s",exp);

    for(i=0;i<strlen(exp);i++)
    {
        if(exp[i]=='['||exp[i]=='{'||exp[i]=='(') // if opening
        {
            push(&s,exp[i]);
        }
        else if (exp[i]==']'||exp[i]=='}'||exp[i]==')') // if closing
        {
            if(IsEmpty(&s))
            {
                valid=FALSE;
                break;
            }
            else
            {
                ch=peek(&s);
                pop(&s);
                if((ch=='[' && exp[i]!=']')||(ch=='{' && exp[i]!='}')||(ch=='(' && exp[i]!=')'));
                {
                    valid=FALSE;
                    break;
                }

            }   
        }
    }
    if(!IsEmpty(&s))
    valid=FALSE;
    if(valid==TRUE)
    printf("\n expression is valid");
    else
    printf("\n expression is invalid");
    return 0;
}
