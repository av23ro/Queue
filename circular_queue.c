#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *que;
    int n;
    int front;
    int rear;
} c_queue;

void enqueue(int x, c_queue *p)
{
    if ((p->rear + 1) % p->n == p->front)
    {
        printf("Queue is full!!\n");
    }
    else if (p->front == -1 && p->rear == -1)
    {
        p->front = 0;
        p->rear = 0;
        p->que[p->rear] = x;
    }
    else
    {
        p->rear = (p->rear + 1) % p->n;
        p->que[p->rear] = x;
    }
}

void dequeue(c_queue *p)
{
    if (p->front == -1 && p->rear == -1)
    {
        printf("Queue is empty!!\n");
    }
    else if (p->front == p->rear)
    {
        printf("Deleted value is : %d\n", p->que[p->front]);
        p->front = -1;
        p->rear = -1;
    }
    else
    {
        printf("Deleted value is : %d\n", p->que[p->front]);
        p->front = (p->front + 1) % p->n;
    }
}

void display(c_queue *p)
{
    int i = p->front;
    if (p->front == -1 && p->rear == -1)
    {
        printf("Queue is empty!!\n");
    }
    else
    {
        while (i != p->rear)
        {
            printf("%d ", p->que[i]);
            i = (i + 1) % p->n;
        }
        printf("%d ", p->que[i]);
        printf("\n");
    }
}

int main()
{
    c_queue *p;
    int ch, x;
    p->front = -1;
    p->rear = -1;
    printf("Enter the size of the queue: ");
    scanf("%d", &p->n);
    p->que = (int *)malloc(p->n * sizeof(int));
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
            return 0;
        default:
            printf("Invalid Choice!!\n");
            break;
        }
    }
    return 0;
}