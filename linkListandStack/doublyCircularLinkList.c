#include<stdio.h>
#include<stdlib.h>
#include<process.h>
struct node{
	int info;
	struct node *next;
	struct node *prev;
};
struct node*header=NULL;
struct node*getnode(int n)
{
	struct node*ptrnew=(struct node*)malloc(sizeof(struct node));
	if(ptrnew=NULL){
		printf("Memory Allocatin Failed");
		getch;
		exit(0);
	}
	ptrnew->info=n;
	ptrnew->next=ptrnew->prev=NULL;
	return ptrnew;
}
void insertAtFront(){
	int n;
	struct node*ptrnew;
	printf("\nEnter new member");
	scanf("%d",&n);
	ptrnew=getnode(n);
	if(header==NULL)
	{
		header=ptrnew;
		header->next=header->prev=header;
	}
	else
	{
		ptrnew->next=header;
		ptrnew->prev=header->prev;
		(header->prev)->next=ptrnew;
		header->prev=ptrnew;
		header=ptrnew;
	}
	printf("\nNode inserted at the front:");
}
void insertAtLast(){
	int n;
	struct node*ptrnew;
	printf("\nEnter new member");
	scanf("%d",&n);
	ptrnew=getnode(n);
	if(header==NULL)
	{
		header=ptrnew;
		header->next=header->prev=header;
	}
	else
	{
		ptrnew->next=header;
		ptrnew->prev=header->prev;
		(header->prev)->next=ptrnew;
		header->prev=ptrnew;
		//header=ptrnew;this makes insert at first
	}
	printf("\nNode inserted at last");
}
void forwardDisplay(){
	struct node*ptrthis;
	if(header=NULL)
	{
		printf("\nList is Empty.");
	}
	else{
		ptrthis=header;
		do{
			printf("%d\t",ptrthis->info);
			ptrthis=ptrthis->next;
			}while(ptrthis!=header);
	}
}
void backwardDisplay(){
	struct node*ptrthis;
	if(header=NULL)
	{
		printf("\nList is Empty.");
	}
	else{
		ptrthis=header->prev;
		do{
			printf("%d\t",ptrthis->info);
			ptrthis=ptrthis->prev;
			}while(ptrthis!=header->prev);
	}
}
void insertAfter(){
	int n,key;
	struct node*ptrthis;
    struct node *ptrnew;
	if(header==NULL){
		printf("List is Empty");
		return;
	}
	printf("\nEnter a number after which you want to add new node:");
	scanf("%d",&key);
	ptrthis=header;
	do{
		if(ptrthis->info==key)//we found a node after which we are going to add.
		{
			printf("\nEnter new node to be inserted.");
			scanf("%d",&n);
			ptrnew=getnode(n);
			ptrnew->prev=ptrthis;
			ptrnew->next=ptrthis->next;
			(ptrthis->next)->prev=ptrnew;
			ptrthis->next=ptrnew;
			printf("\nNode inserted After %d",key);
			return;
				}	
				ptrthis=ptrthis->next;//go ahead	
	}	while(ptrthis!=header);
	printf("%d not found in the list,",key);
}
int main()
{
char ch;
do{
	printf("1.Insert at front\n2.Insert at last\n3.Insert After");
	printf("4.Insert before\n5.Remove from last\n6.Remove from front");
	printf("7.Remove any\n8.Frontward Display\n9.Backward display");
	printf("\nx.Exit");
}	
}
