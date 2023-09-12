#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
   int info;
   struct node*next;
};
struct node*header;
struct node*getnode(int info)
{
   struct node*ptrnew;
   ptrnew=(struct node*)malloc(sizeof(struct node));
   if(ptrnew==NULL)
   {
      printf("Memory allocation failed.");
      getch();
      exit(0);
   }
   ptrnew->info=info;
   ptrnew->next=NULL;
   return ptrnew;
}
void insertAtFront()
{
   struct node*ptrnew;
   int data;
   printf("Enter your number");
   scanf("%d",&data);
   ptrnew=getnode(data);
   if(header==NULL)
   {
      header=ptrnew;
      ptrnew->next=header;
   }
   else{
      ptrnew->next=header->next;
      header->next=ptrnew;
   }
   printf("Inserted at the front.");
}
void insertAtLast()
{
   struct node*ptrnew;
   int data;
   printf("Enter your number");
   scanf("%d",&data);
   ptrnew=getnode(data);
   if(header==NULL)
   {
      header=ptrnew;
      ptrnew->next=ptrnew;//header->next=header;
   }
   else{
      ptrnew->next=header->next;
      header->next=ptrnew;
   }
   header=header->next;//this is the only differnt
   printf("Inserted at the end.");
}
void insertAfter()
{
   int key,data;
   struct node*ptrthis,*ptrnew;
   if(header==NULL)
      printf("List is empty.");
   else
   {
     printf("Enter a number after which you want to insert:");
     scanf("%d",&key);
     ptrthis=header;
     do{
	if(ptrthis->info==key)
	{
	   printf("Enter a number you want to insert after %d",key);
	   scanf("%d",&data);
	   ptrnew=getnode(data);
	   ptrnew->next=ptrthis->next;
	   ptrthis->next=ptrnew;
	   if(ptrthis==header)
	     header=header->next;
	   printf("Inserted after %d",key);
	   return;
	}
	ptrthis=ptrthis->next;
     }while(ptrthis!=header);
     printf("Node with key %d does not exist.",key);
   }
}
void removeFromFront()
{
    struct node*ptrthis;
    if(header==NULL)
    {
     printf("List is empty.");
     return;
    }
    if(header==header->next)//having only one node
    {
       ptrthis=header;
       header=NULL;
    }
    else
    {
       ptrthis=header->next;
       header->next=ptrthis->next;
    }
    free(ptrthis);
    printf("Removed from front.");
}
void removeFromLast()
{
    struct node*ptrthis;
    if(header==NULL)
    {
     printf("List is empty.");
     return;
    }
    if(header==header->next)//having only one node
    {
       ptrthis=header;
       header=NULL;
    }
    else//if more than one node in the list then find second last node and then delete the current last
    {
       for(ptrthis=header;ptrthis->next!=header;ptrthis=ptrthis->next);//search for second last node
       header=ptrthis;//make second last as the last node and then delete the last one
       ptrthis=header->next;
       header->next=ptrthis->next;
    }
    free(ptrthis);
    printf("Removed from last.");
}
void removeAny()
{
    struct node*ptrthis,*ptrprev;
    int key;
    if(header==NULL)
    {
     printf("List is empty.");
     return;
    }
    printf("Enter key to remove");
    scanf("%d",&key);
    ptrthis=header;
    do{
       ptrprev=ptrthis;
       ptrthis=ptrthis->next;
       if(ptrthis->info==key)//if key found then delete the current node
       {
	  if(ptrprev==ptrthis)//having only one node
	    header=NULL;
	  else//if more than one node in the list
	  {
	    ptrprev->next=ptrthis->next;//bypass the current node
	    if(ptrthis==header)//if last node is to be removed then set previous node as last node
	      header=ptrprev;
	  }
	  free(ptrthis);
	  printf("Removed from list.");
	  return;
       }
    }while(ptrthis!=header);
    printf("Key not found.");
}
void display()
{
    struct node*ptrthis;
    if(header==NULL)
      printf("List is empty.");
    else
    {
       printf("List contains:\n");
       ptrthis=header->next;
       do{
	  printf("%d\t",ptrthis->info);
	  ptrthis=ptrthis->next;
       }while(ptrthis!=header->next);
    }
}
void main()
{
   char ch;
   header=NULL;
   do{
     
      printf("Select your option:");
      printf("\n1. Insert At Front\n2. Insert At Last\n3. Insert After");
      printf("\n4. Remove From Front\n5. Remove From Last\n6. Remove Any");
      printf("\n7. Display List\n8. Exit Program\n");
      ch=getche();
      switch(ch)
      {
	 case '1':insertAtFront();break;
	 case '2':insertAtLast();break;
	 case '3':insertAfter();break;
	 case '4':removeFromFront();break;
	 case '5':removeFromLast();break;
	 case '6':removeAny();break;
	 case '7':display();break;
	 case '8':
		printf("Good bye");getch();return;
      }
      getch();
   }while(1);
}