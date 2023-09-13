#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int front;
    int rear;
    int *que;
    int size;
} queue;

void enqueue(int x, queue *p)
{
    if (p->rear == p->size - 1)
    {
        printf("Overflow!!\n");
    }
    else if (p->rear == -1 && p->front == -1)
    {
        p->front = 0;
        p->rear = 0;
        p->que[p->rear] = x;
    }
    else
    {
        p->rear++;
        p->que[p->rear] = x;
    }
}
void dequeue(queue *p)
{
    if (p->front > p->rear)
    {
        printf("Underflow!!\n");
    }
    else if (p->front == -1 && p->rear == -1)
    {
        p->front = 0;
        p->rear = 0;
    }
    else
    {
        printf("Deleted item is %d\n", p->que[p->front]);
        p->front++;
    }
}
void display(queue *p)
{
    int i;
    if (p->front == -1 && p->rear == -1)
    {
        printf("Empty Queue!!\n");
    }
    else
    {
        for (i = p->front; i <= p->rear; i++)
        {
            printf("%d \n", p->que[i]);
        }
    }
}
int main()
{
    queue *p;
    int ch, x;
    printf("Enter the size of the queue: ");
    scanf("%d", &p->size);
    p->front = -1;
    p->rear = -1;
    p->que = (int *)malloc(p->size * sizeof(int));
    while (1)
    {
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the value you want to enqueue: ");
            scanf("%d", &x);
            enqueue(x, p);
            break;
        case 2:
            dequeue(p);
            break;
        case 3:
            display(p);
            break;
        case 4:
            free(p->que);
            exit(0);
        default:
            printf("Invalid Choice!!\n");
            break;
        }
    }
    return 0;
}
