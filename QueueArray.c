#include <stdio.h>
#define SIZE 5

typedef struct Queue
{
    int fi;
    int ri;
    int a[SIZE];
} q;

int isfull(q *q1)
{
    if (q1->ri == SIZE - 1)
    {
        printf("\nQueue is Full");
        return 1;
    }
    return 0;
}

int isempty(q *q1)
{
    if (q1->ri == -1)
    {
        printf("\nQueue is Empty");
        return 1;
    }
    return 0;
}

int Enqueue(q *q1, int n)
{

    int j = isfull(q1);
    if (j == 1)
    {
        return;
    }

    if (q1->fi == -1)
    {
        q1->fi++;
        q1->ri++;
        q1->a[q1->ri] = n;

        return;
    }
    else
    {
        q1->ri++;
        q1->a[q1->ri] = n;

        return;
    }
}

int Dequeue(q *q1)
{
    int j = isempty(q1);
    if (j == 1)
    {
        return;
    }
    printf("\nThe deleted element is %d", q1->a[q1->fi]);
    if (q1->ri == q1->fi)
    {
        q1->fi = -1;
        q1->ri = -1;
        return;
    }

    else
    {
        q1->fi++;
        return;
    }
}

int Display(q *q1)
{
    if (isempty(q1))
    {
    }
    else
    {
        printf("\nThe Queue is:");
        for (int i = q1->fi; i <= q1->ri; i++)
        {
            printf("\n%d", q1->a[i]);
        }
    }
}

int main()
{
    q q1;
    q1.fi = q1.ri = -1;
    int b, c;
    do
    {
        printf("\nMain Menu");
        printf("\n1. Enqueue");
        printf("\n2.Dequeue");
        printf("\n3.Display");
        printf("\n4.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &b);

        switch (b)
        {
        case 1:
            printf("\nEnter the no. for Enqueue: ");
            scanf("%d", &c);
            Enqueue(&q1, c);
            break;
        case 2:
            Dequeue(&q1);
            break;
        case 3:
            Display(&q1);
            break;
        default:
            printf("\nEXIT");
        }

    } while (b != 4);
}
