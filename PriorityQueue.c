#include <stdio.h>
#include <stdlib.h>

struct node
{
    int priority;
    int info;
    struct node *next;
};

struct node *front = NULL;

void insert(int data, int priority)
{
    struct node *temp, *q;

    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = data;
    temp->priority = priority;

    if (front == NULL || priority < front->priority)
    {
        temp->next = front;
        front = temp;
    }
    else
    {
        q = front;
        while (q->next != NULL && q->next->priority <= priority)
            q = q->next;
        temp->next = q->next;
        q->next = temp;
    }
}

void del()
{
    struct node *temp;

    if (front == NULL)
        printf("Queue Underflow\n");
    else
    {
        temp = front;
        printf("Deleted data is %d\n", temp->info);
        front = front->next;
        free(temp);
    }
}

void display()
{
    struct node *ptr;
    ptr = front;
    if (front == NULL)
        printf("Queue is empty\n");
    else
    {
        printf("Queue is :\n");
        printf("Data       Priority\n");
        while (ptr != NULL)
        {
            printf("%2d        %4d\n", ptr->info, ptr->priority);
            ptr = ptr->next;
        }
    }
}

int main()
{
    int ch, data, priority;
    do
    {
        printf("\nMain Menu");
        printf("\n1.Insert");
        printf("\n2.Delete");
        printf("\n3.Display");
        printf("\n4.Exit");
        printf("\nEnter the choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the value to insert:  ");
            scanf("%d", &data);
            printf("Enter its priority : ");
            scanf("%d", &priority);
            insert(data, priority);
            break;
        case 2:
            del();
            break;
        case 3:
            display();
            break;
        default:
            printf("\nExit");
        }
    } while (ch != 4);

    return 0;
}