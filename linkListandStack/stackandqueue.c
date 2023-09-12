#include<stdio.h>
#include<stdlib.h>
#define MAX 10
struct queue
{
    int item[MAX];
    int rear;
};
void enqueue(struct queue*q, int val)
{
    if (q->rear==MAX-1)
    {
        printf("queue is full. you cannot insert more items.");
        return;        
    }
    q->rear++;
    q->item[q->rear]=val;
    printf("item inserted successfully");
    return;
}
int dequeue(struct queue*q)
{
    int val, i;
    if(q->rear==-1)
    {
        printf("queue is empty. you cannot remove any items from an empty queue");
        exit(0);
    }
    val=q->item[0];
    for (i=1;i<=q->rear;i++)
    q->item[i=1]=q->item[i];
    q->rear--;
    return val;
}
void display(struct queue q)
{
    int i;
    if(q.rear==1)
    printf("queue is empty");
    else
    {
        printf("\n queue contains:\n");
        for(i=0;i<=q.rear;i++)
        printf("%d\t",q.item[i]);
    }
}
void main()
{
    struct queue q;
    char ch;
    q.rear=-1;
    while(1)
    {
        system("cls");
        printf("select an option:\n1. Enquire\n2. Dequeue\n3. Display\n4. Exit");
        ch=getche();
        switch(ch)
        {
            case '1':
            int n;
            printf("\nenter a number:");
            scanf("%d",&n);
            enqueue(&q,n);
            break;
            case '2':
            if(q.rear==-1)
            printf("queue is empty");
            else
            {
                n=dequeue(&q);
                printf("\n%d was removed.",n);

            }
            break;
            case'3':
            display(q);
            break;
            case '4':return;
        }
        getch();
    }
}