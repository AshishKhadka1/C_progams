#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define TRUE 1
#define FALSE 0
struct queue
{
    int item[MAX];
    int rear;
    int front;
};
int GetNextPosition(int n)
{
    if (n == MAX - 1)
        return 0;
    else

    return n +1;
}
int IsFull(struct queue q)
{
    if (q.front == GetNextPosition(q.rear))
        return TRUE;
    else
        return FALSE;
}
int IsEmpty(struct queue q)
{
    if (q.front == q.rear)
        return TRUE;
    else
        return FALSE;
    // RETURN Q.FRONT==Q.REAR;
}
void enqueue(struct queue *q, int n)
{
    q->rear = GetNextPosition(q->rear);
    q->
}



int main()
{
    struct queue q;
    char choice;
    int n;
    q.front=q.rear=MAX-1;//empty queue
    while(TRUE)
    {
        printf("select your choice:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit")
        choice=getche();
        switch choice
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
// incompletes