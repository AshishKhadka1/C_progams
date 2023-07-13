#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *header = NULL; // first node lai pointer garnea external pointer declared as null ..G L O B A L

struct node *getnode(int n)
{
    struct node*ptrnew = (struct node*)malloc(sizeof(struct node));
    if (ptrnew == NULL)
    {
        printf("\nFAILED");
        getch();
        exit(0);
    }
    ptrnew->data = n;
    ptrnew->next = ptrnew->prev = NULL; // front and back both null
    return ptrnew;
}
void insertAtFront()
{
    struct node *ptrnew;
    int n;
    printf("\nEnter Number:");
    scanf("%d", &n);
    ptrnew = getnode(n);
    if (header != NULL)
    {
        ptrnew->next = header;
        header->prev = ptrnew;
    }
    header = ptrnew;
    printf("\nNumber inserted at front");
}
void insertAtBack()
{
    struct node *ptrnew, *ptrthis;
    int n;
    printf("\nEnter Number:");
    scanf("%d", &n);
    ptrnew = getnode(n);
    if (header == NULL)
        header = ptrnew;
    else
    {
        for (ptrthis = header; ptrthis->next != NULL; ptrthis = ptrthis->next)
            ;
        ptrthis->next = ptrnew;
        ptrnew->prev = ptrthis;
    }
    printf("\nNode Inserted At The End.");
}

void atBack()
{
    int n, target;
    struct node *ptrnew, *ptrthis;

    printf("\nEnter Number After Which you want to insert: ");
    scanf("%d", &target);

    for (ptrthis = header; ptrthis != NULL; ptrthis = ptrthis->next)
    {
        if (ptrthis->data == target)
        {
            printf("\nEnter Data to Insert in the Middle: ");
            scanf("%d", &n);
            ptrnew = getnode(n);
            ptrnew->next = ptrthis->next;
            ptrnew->prev = ptrthis;
            if (ptrthis->next != NULL)
                (ptrthis->next)->prev = ptrnew;
            ptrthis->next = ptrnew;
            return;
        }
    }
    printf("\nNot Found Number");
}

void insertBefore()
{
    int n, target;
    struct node *ptrnew, *ptrthis;

    printf("\nEnter Number Before Which you want to insert: ");
    scanf("%d", &target);

    if (header->data == target)
    {
        printf("\nEnter Data to Insert at the Beginning: ");
        scanf("%d", &n);
        ptrnew = getnode(n);
        ptrnew->next = header;
        header->prev = ptrnew;
        header = ptrnew;
        return;
    }

    for (ptrthis = header; ptrthis != NULL; ptrthis = ptrthis->next)
    {
        if (ptrthis->data == target)
        {
            printf("\nEnter Data to Insert in the Middle: ");
            scanf("%d", &n);
            ptrnew = getnode(n);
            ptrnew->next = ptrthis;
            ptrnew->prev = ptrthis->prev;
            (ptrthis->prev)->next = ptrnew;
            ptrthis->prev = ptrnew;
            return;
        }
    }
    printf("\nNot Found Number");
}
void display()
{
    struct node *ptrthis;
    if (header == NULL)
    {
        printf("\nEMPTY");
    }
    else
    {
        for (ptrthis = header; ptrthis != NULL; ptrthis = ptrthis->next)
        {
            printf("%d\t", ptrthis->data);
        }
    }
}

void removefromfront()

{

    int n, target;
    struct node *ptrthis;
    if (header == NULL)
    {
        printf("\nList Empty.");
    }

    else
    {

        ptrthis = header;
        header = header->next;
        if (header != NULL)
        {
            header->prev = NULL; // condition in one then more ..
        }
        free(ptrthis);
        printf("\nNode Removed From Front.");
    }
}
void removeFromLast()
{

    struct node *ptrthis; // to search last node
    if (header == NULL)
    {
        printf("\nList Empty.");
    }
    else
    {
        for (ptrthis = header; ptrthis->next != NULL; ptrthis = ptrthis->next)
            ;
        if (ptrthis == header)
        {
            header = NULL;
        }
        else

            (ptrthis->prev)->next = NULL;
        free(ptrthis);
        printf("\nNode Removed from Last.");
    }
}

void removeAny()
{

    struct node *ptrthis, *ptrprev;
    int target;
    printf("\nEnter A Number to be remove:\n");
    scanf("%d", &target);
    for (ptrthis = header; ptrthis != NULL; ptrthis = ptrthis->next)
        ;
    {
        if (ptrthis->data == target)
        {
            if (ptrthis == header) // first node is gonna be removed
            {

                header = header->next;
                if (header != NULL)
                    header->prev = NULL;
            }
            else if (ptrthis->next == NULL) // last node ...

                (ptrthis->prev)->next = NULL;
        }
        else // intermidate nodes
        {

            (ptrthis->prev)->next = ptrthis->next;
            (ptrthis->next)->prev = ptrthis->prev;
        }
        free(ptrthis);
        printf("\nNode Removed.");
        return;
    } // if node found then delete it and return
    printf("\nNot Found.");
}

int main()
{
    char ch;
    while (1)
    {
        system("cls");
        printf("\nSELECT OPTION\n1.InsertAtfront\n2.InsertAtBack\n3.AtBack\n4.insertBefore\n5.Display\n6.removefromfront\n");
        printf("7.removeFromLast\n8.RemoveANy\n9.Exit\n\n");
        ch = getche();
        switch (ch)
        {
        case '1':
            insertAtFront();
            break;
        case '2':
            insertAtBack();
            break;
        case '3':
            atBack();
            break;
        case '4':
            insertBefore();
            break;

        case '5':
            printf("\n");
            display();
            break;

        case '6':
            removefromfront();
            break;

        case '7':
            removeFromLast();
            break;

        case '8':
            removeAny();
            break;

        default:
            printf("\nInvalid Option");
            break;
        }
        getch();
    }
}
