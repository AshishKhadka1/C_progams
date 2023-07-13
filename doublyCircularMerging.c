// /*  Algorithm to merge the douly circular link list
// step 1: (header1->prev)->next=header2
// step 2: ptrthis=header2->prev;
// step 3: header2->prev=header1->prev;
// step 4: ptrthis->next=header1;
// step 5: header1->prev=ptrthis;
// */
// #include<stdio.h>
// #include<conio.h>
// #include<stdlib.h>
// #include<process.h>
// struct node{
// 	int info;
// 	struct node *next;
// 	struct node *prev;
// };
// struct node*header=NULL;
// struct node*getnode(int n)
// {
// 	struct node*ptrnew=(struct node*)malloc(sizeof(struct node));
// 	if(ptrnew=NULL){
// 		printf("Memory Allocatin Failed");
// 		getch;
// 		exit(0);
// 	}

// }#