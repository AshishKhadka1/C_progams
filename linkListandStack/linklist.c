#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;          // holds the actual data in a node.
    struct node *next; // holds the address of the next node in the list
};

struct node *header = NULL; // empty list realization

struct node *getnode(int n)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed.");
        exit(0);
    }
    newnode->data = n;
    newnode->next = NULL;
    return newnode;
}

void insertAtLast()
{
    int n;
    struct node *ptrnew, *ptrthis;
    printf("\nEnter a number: ");
    scanf("%d", &n);
    ptrnew = getnode(n);
    if (header == NULL)
        header = ptrnew;
    else
    {
        for (ptrthis = header; ptrthis->next != NULL; ptrthis = ptrthis->next)
        {
            // do nothing
        }
        ptrthis->next = ptrnew;
    }
    printf("\nNode inserted at the end.");
}

void display()
{
    struct node *ptrthis;
    if (header == NULL)
        printf("\nList is empty.");
    else
    {
        printf("\nList contains:\n");
        for (ptrthis = header; ptrthis != NULL; ptrthis = ptrthis->next)
        {
            printf("%d\t", ptrthis->data);
        }
    }
}

int main()
{
    char ch;
    while (1)
    {
        system("CLS");
        printf("Select an option:\n1. Insert\n2. Remove\n3. List\n4. Exit\n");
        ch = getchar();
        switch (ch)
        {
        case '1':
            insertAtLast();
            break;
        case '2':
            break;
        case '3':
            display();
            break;
        case '4':
            return 0;
        }
        getchar();
    }
}

