#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *insert(struct node *head, int no)
{
    struct node *help_ptr;
    help_ptr = head;
    struct node *pnew = (struct node *)malloc(sizeof(struct node));
    pnew->data = no;
    pnew->next = NULL;
    if (head == NULL)
    {
        head = pnew;
        return head;
    }
    if (head->data > no)
    {
        pnew->next = head;
        head = pnew;
        return head;
    }
    else
    {
        while (help_ptr->next != NULL && help_ptr->next->data < no)
        {
            help_ptr = help_ptr->next;
        }
        pnew->next = help_ptr->next;
        help_ptr->next = pnew;
        return head;
    }
}

void display(struct node *help_ptr)
{

    if (help_ptr == NULL)
    {
        printf("\nList is Empty");
    }
    else
    {
        printf("\n\nLinked List is:");
        while (help_ptr != NULL)
        {
            printf("\n %d", help_ptr->data);
            help_ptr = help_ptr->next;
        }
    }
}

struct node *delete (int x, struct node *head)
{
    struct node *help_ptr = head;
    struct node *n2d;
    if (help_ptr == NULL)
    {
        printf("\nLinked List is Empty");
    }
    else
    {
        if (help_ptr->data == x)
        {
            head = help_ptr->next;
            free(help_ptr);
            return head;
        }
        while (help_ptr->next != NULL)
        {

            if (help_ptr->next->data == x)
            {
                n2d = help_ptr->next;
                help_ptr->next = help_ptr->next->next;
                free(n2d);
                return head;
            }
            help_ptr = help_ptr->next;
            if (help_ptr->next == NULL)
            {
                printf("\nElement not found");
            }
        }
    }
}

int main()
{
    int ch, n, d;
    struct node *head;
    head = NULL;

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
            printf("\nEnter the value to insert: ");
            scanf("%d", &n);
            head = insert(head, n);
            break;
        case 2:
            printf("\nEnter the value to delete: ");
            scanf("%d", &d);
            head = delete (d, head);
            break;
        case 3:
            display(head);
            break;
        default:
            printf("Exit");
        }

    } while (ch != 4);
}