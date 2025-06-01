#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void printQueue()
{
    printf("Contents of your Queue:\n");

    struct Node *temp = front;
    if (temp == NULL)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("Element: %d\n", temp->data);
            temp = temp->next;
        }
    }
}

void CreateQueue()
{
    front = NULL;
    rear = NULL;

    printf("Queue created.\n");
    printQueue();
}

void enqueue(int value)
{
    struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));

    if (NewNode == NULL)
    {
        printf("Queue is full.\n");
    }
    else
    {
        NewNode->data = value;
        if (rear == NULL)
        {
            front = rear = NewNode;
        }
        else
        {
            rear->next = NewNode;
            rear = NewNode;
        }
        NewNode->next = NULL;
    }

    printf("Element pushed.\n");
    printQueue();
}

void dequeue()
{
    if (front == NULL)
    {
        printf("Queue is empty. Nothing to dequeue.\n");
    }
    else
    {
        struct Node *Q;
        Q = front;
        front = front->next;
        printf("Popped element: %d\n", Q->data);
        if (isEmpty())
        {
            rear = NULL;
        }
        free(Q);
    }
    printQueue();
}

int isEmpty()
{
    if (front == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Peek()
{
    if (front == NULL)
    {
        printf("Queue is empty. Nothing to display.\n");
    }
    else
    {
        printf("Top Element: %d\n", front->data);
    }
}

void BottomElement()
{
    if (rear == NULL)
    {
        printf("Queue is Empty.\n");
    }
    else
    {
        printf("Bottom Element: %d\n", rear->data);
    }
}

int menu()
{
    int choice;
    printf("\nEnter 1 if you want to create a new Queue\n");
    printf("Enter 2 if you want to push an element\n");
    printf("Enter 3 if you want to dequeue the front element\n");
    printf("Enter 4 if you want to check if the Queue is empty\n");
    printf("Enter 5 if you want to return the top element without popping it\n");
    printf("Enter 6 if you want to return the bottom most element\n");
    printf("Enter 7 if you want to print the Queue\n");
    printf("Enter 0 to Exit the program\n");
    scanf("%d", &choice);
    return choice;
}

int main()
{
    int value, choice, empty;

    do
    {
        choice = menu();
        switch (choice)
        {
        case 1:
            CreateQueue();
            break;
        case 2:
            printf("Enter the element to push:\n");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 3:
            dequeue();
            break;

        case 4:
            empty = isEmpty();
            if (empty == 1)
            {
                printf("Queue is empty.\n");
            }
            else
            {
                printf("Queue is not empty.\n");
            }
            break;

        case 5:
            Peek();
            break;

        case 6:
            BottomElement();
            break;

        case 7:
            printQueue();
            break;

        case 0:
            printf("Exiting the program :) .\n");
            break;

        default:
            printf("Enter a valid choice.\n");
            break;
        }
    } while (choice != 0);

    while (front != NULL)
    {
        struct Node *temp = front->next;
        free(front);
        front = temp;
    }

    return 0;
}