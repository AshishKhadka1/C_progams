#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int info; // int data;
    struct node *next;
};
struct node *header;
struct node *GetNode(int num)
{
    struct node *ptrnew;
    ptrnew = (struct node *)malloc(sizeof(struct node));
    if (ptrnew == NULL)
    {
        printf("\nMemory allocation failed.");
        getch();
        exit(0);
    }
    ptrnew->next = NULL;
    ptrnew->info = num;
    return ptrnew;
}
void InsertAtFront()
{
    int num;
    struct node *ptrnew;
    printf("\nEnter a number to be added :");
    scanf("%d", &num);
    ptrnew = GetNode(num); // now we have required node to be inserted.
    if (header == NULL)
        header = ptrnew;
    else
    {
        ptrnew->next = header; // new node's next field is set to current front node
        header = ptrnew;       // now new node becomes front node
    }
    printf("\nItem inserted at the front.");
}
void InsertAtBack()
{
    int num;
    struct node *ptrnew, *ptrthis;
    printf("\nEnter a number to be added :");
    scanf("%d", &num);
    ptrnew = GetNode(num); // now we have required node to be inserted.
    if (header == NULL)
        header = ptrnew;
    else
    {
        ptrthis = header; // start from front node
        while (ptrthis->next != NULL)
            ptrthis = ptrthis->next; // move to next node until next node is empty
        ptrthis->next = ptrnew;
    }
    printf("\nItem inserted at the rear.");
}
void InsertAfter()
{
    int num, key;
    struct node *ptrnew, *ptrthis;
    if (header == NULL)
        printf("\nList is empty.");
    else
    {
        printf("\nEnter a number after which you want to insert :");
        scanf("%d", &key);
        ptrthis = header; // start from front node
        while (ptrthis->info != key)
        {
            ptrthis = ptrthis->next; // move to next node until next node is empty
            if (ptrthis == NULL)
            {
                printf("\nKey not found.");
                return;
            }
        }
        printf("\nEnter a number to be added :");
        scanf("%d", &num);
        ptrnew = GetNode(num); // now we have required node to be inserted.
        ptrnew->next = ptrthis->next;
        ptrthis->next = ptrnew;
        printf("\nItem inserted after %d.", key);
    }
}
// insert before is left as exercise
void RemoveFromFront()
{
    struct node *ptrthis;
    if (header == NULL)
        printf("\nList is empty.");
    else
    {
        ptrthis = header;
        header = header->next;
        free(ptrthis);
        printf("\nItem removed from front.");
    }
}
void RemoveFromBack()
{
    struct node *ptrthis, *prev;
    if (header == NULL)
        printf("\nList is empty.");
    else if (header->next == NULL)
    {
        ptrthis = header;
        header = NULL;
        free(ptrthis);
        printf("\nItem removed from last.");
    }
    else
    {
        ptrthis = header;
        while (ptrthis->next != NULL)
        {
            prev = ptrthis;
            ptrthis = ptrthis->next;
        }
        prev->next = NULL;
        free(ptrthis);
        printf("\nItem removed from last.");
    }
}
void RemoveAny()
{
    int key;
    struct node *ptrthis, *prev;
    if (header == NULL)
        printf("\nNothing to remove.");
    else
    {
        printf("\nEnter your key to remove");
        scanf("%d", &key);
        ptrthis = header;
        while (ptrthis->info != key)
        {
            prev = ptrthis;
            ptrthis = ptrthis->next;
            if (ptrthis == NULL)
            {
                printf("Key does not exist.");
                return;
            }
        }
        if (ptrthis == header) // if first node is to be removed
            header = header->next;
        else // other than first node
            prev->next = ptrthis->next;
        free(ptrthis);
        printf("\nItem removed.");
    }
}
void Display()
{
    struct node *ptrthis;
    if (header == NULL)
        printf("\nList is empty.");
    else
    {
        printf("\nList contains:\n");
        for (ptrthis = header; ptrthis != NULL; ptrthis = ptrthis->next)
            printf("%d\t", ptrthis->info);
    }
}
void main()
{
    char choice;
    header = NULL; // initially list is empty
    while (1)
    {
        system("cls");
        // clrscr();
        printf("Select your choice:\n");
        printf("1. Insert at front\n2. Insert at back\n3. Insert After\n");
        printf("4. Remove from front\n5. Remove from back\n6. Remove Any\n");
        printf("7. Display\n8. Exit\n");
        choice = getche();
        switch (choice)
        {
        case '1':
            InsertAtFront();
            break;
        case '2':
            InsertAtBack();
            break;
        case '3':
            InsertAfter();
            break;
        case '4':
            RemoveFromFront();
            break;
        case '5':
            RemoveFromBack();
            break;
        case '6':
            RemoveAny();
            break;
        case '7':
            Display();
            break;
        case '8':
            printf("Good bye");
            getch();
            exit(0);
        default:
            printf("Invalid choice. Try again!");
        }
        getch();
    }
}