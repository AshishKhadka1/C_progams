#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAX 100
typedef struct{
	float items[MAX];
	int tos;
}stack;
void push(stack*s,float val)
{
	s->items[++s->tos]=val;
}
float pop(stack*s)
{
	return s->items[s->tos--];
	
}
int main()
{
	stack s;
	char str[MAX];
	float op1,op2,val;
	int i;
	s.tos=-1;
	printf("Enter your postfix expression:");
	gets(str);
	
	for(i=0;i<strlen(str);i++)
	{
		switch(str[i])
		{
			case'+':
				op2=pop(&s);
				op1=pop(&s);
				push(&s,op1+op2);break;
			case'-':
				op2=pop(&s);
				op1=pop(&s);
				push(&s,op1-op2);break;
			case'*':
				op2=pop(&s);
				op1=pop(&s);
				push(&s,op1*op2);break;
			case'/':
				op2=pop(&s);
				op1=pop(&s);
				push(&s,op1/op2);break;
			case'$':
				op2=pop(&s);
				op1=pop(&s);
				push(&s,pow(op1,op2));break;
			default:
				printf("\nEnter the value of %c",str[i]);
				scanf("%f",&val);
				
				
		}
	}
	printf("\nValue of expression:%f",pop(&s));
	getc ; 
}
