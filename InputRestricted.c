#include <stdio.h>
#include <stdlib.h>

typedef struct qnode
{
    int data;
    struct qnode *next;
} q;

q *front = NULL;
q *rear = NULL;

void enqueue(int n)
{
    q *new1 = (q *)malloc(sizeof(q));
    new1->data = n;
    new1->next = NULL;

    if (front == NULL)
    {
        front = new1;
        rear = new1;
        return;
    }
    rear->next = new1;
    rear = new1;
    return;
}
void display()
{
    q *i;
    if (front == NULL)
    {
        printf("\n Queue Empty");
        return;
    }
    for (i = front; i != NULL; i = i->next)
    {
        printf(" %d\n", i->data);
    }
}
void dequeueFront()
{
    if (rear == NULL)
    {
        printf("\n Queue Empty");
        return;
    }
    q *temp;
    temp = front;
    printf("\n The deleted item is %d", front->data);
    if (rear == front)
    {
        rear = NULL;
        front = NULL;
        return;
    }
    front = front->next;
    free(temp);
    return;
}

void dequeueRear()
{
    if (rear == NULL)
    {
        printf("\n Queue Empty");
        return;
    }

    printf("\n The deleted item is %d", rear->data);
    if (rear == front)
    {
        rear = NULL;
        front = NULL;
        return;
    }
    q *temp;
    temp = front;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(rear);
    rear = temp;
    rear->next = NULL;
    return;
}

int main()
{
    int ch, n;
    q *front = NULL;
    q *rear = NULL;

    do
    {
        printf("\nMain Menu");
        printf("\n1.Insert");
        printf("\n2.Delete Front");
        printf("\n3.Delete Rear");
        printf("\n4.Display");
        printf("\n5.Exit");
        printf("\nEnter the choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the value to insert: ");
            scanf("%d", &n);
            enqueue(n);
            break;
        case 2:
            dequeueFront();
            break;
        case 3:
            dequeueRear();
            break;
        case 4:
            display();
            break;
        default:
            printf("Exit");
        }

    } while (ch != 5);
}