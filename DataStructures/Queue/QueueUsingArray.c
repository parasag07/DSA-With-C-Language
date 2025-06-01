#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int FrontInd;
    int BackInd;
    int *Queue;
};

void printQueue(struct Queue *Q)
{
    int i;
    printf("Contents of the Queue: \n");
    if (Q->BackInd != -1)
    {
        i = Q->FrontInd + 1;
        while (i < Q->BackInd + 1)
        {
            printf("Element: %d \n", Q->Queue[i]);
            i++;
        }
    }
    else
    {
        printf("Queue is empty.\n");
    }
}

struct Queue *CreateQueue()
{
    struct Queue *Q = (struct Queue *)malloc(sizeof(struct Queue));
    printf("Enter the size of Queue\n");
    scanf("%d", &Q->size);
    Q->FrontInd = -1;
    Q->BackInd = -1;
    Q->Queue = (int *)malloc(Q->size * sizeof(int));
    printf("Queue is created.\n");
    printQueue(Q);
    return Q;
}

void push(struct Queue *Q, int value)
{
    if (Q->BackInd == Q->size - 1)
    {
        printf("Queue is full! \n");
    }
    else
    {
        Q->BackInd++;
        Q->Queue[Q->BackInd] = value;
    }
    printQueue(Q);
}

void pop(struct Queue *Q)
{
    if (Q->FrontInd == Q->BackInd)
    {
        printf("Queue is empty! \n");
    }
    else
    {
        Q->FrontInd++;
        printf("Popped Element: %d\n", Q->Queue[Q->FrontInd]);
        printQueue(Q);
    }
}

void ValueAtPosition(struct Queue *Q, int pos)
{
    if (pos > Q->size - 1 || pos <= Q->FrontInd)
    {
        printf("Invalid position. \nEnter a valid position.\n");
    }
    else if (pos > (Q->BackInd))
    {
        printf("There is no value present at the given position.\n");
    }
    else
    {
        printf("%d", Q->Queue[pos]);
    }
}

void isEmpty(struct Queue *Q)
{
    if (Q->BackInd == Q->FrontInd)
    {
        printf("Queue is Empty.\n");
    }
    else
    {
        printf("Queue is not Empty.\n");
    }
}

void isFull(struct Queue *Q)
{
    if (Q->BackInd == Q->size - 1)
    {
        printf("Queue is Full.\n");
    }
    else
    {
        printf("Queue is not Full.\n");
    }
}

void Peek(struct Queue *Q)
{
    if (Q->BackInd == -1)
    {
        printf("Queue is empty. Nothing to display\n");
    }
    else
    {
        printf("Last Entered Element: %d\n", Q->Queue[Q->BackInd]);
    }
}

void BottomElement(struct Queue *Q)
{
    if (Q->BackInd == Q->FrontInd)
    {
        printf("Queue is Empty.\n");
    }
    else
    {
        printf("Bottom Element: %d\n", Q->Queue[Q->FrontInd + 1]);
    }
}

int menu()
{
    int choice;
    printf("\nEnter 1 if you want to create a new Queue\n");
    printf("Enter 2 if you want to push an element\n");
    printf("Enter 3 if you want to pop the front element\n");
    printf("Enter 4 if you want to get value at given position from the top\n");
    printf("Enter 5 if you want to check if the Queue is empty\n");
    printf("Enter 6 if you want to check if the Queue is full\n");
    printf("Enter 7 if you want to return the top element without popping it\n");
    printf("Enter 8 if you want to return the bottom most element\n");
    printf("Enter 9 if you want to print the Queue\n");
    printf("Enter 0 to Exit the program\n");
    scanf("%d", &choice);
    return choice;
}

int main()
{
    int value, pos, choice;

    struct Queue *Q = (struct Queue *)malloc(sizeof(struct Queue));
    Q->size = 100;
    Q->FrontInd = -1;
    Q->BackInd = -1;
    Q->Queue = (int *)malloc(Q->size * sizeof(int));

    do
    {
        choice = menu();
        switch (choice)
        {
        case 1:
            Q = CreateQueue();
            break;
        case 2:
            printf("Enter the element to push:\n");
            scanf("%d", &value);
            push(Q, value);
            break;
        case 3:
            pop(Q);
            break;

        case 4:
            printf("Enter the position at which you want the value:\n");
            scanf("%d", &pos);
            ValueAtPosition(Q, pos);
            break;

        case 5:
            isEmpty(Q);
            break;

        case 6:
            isFull(Q);
            break;

        case 7:
            Peek(Q);
            break;

        case 8:
            BottomElement(Q);
            break;

        case 9:
            printQueue(Q);
            break;
            
        case 0: 
            printf("Exiting the program.\n");
            break;

        default:
            break;
        }
    } while (choice != 0);

    free(Q->Queue);
    free(Q);

    return 0;
}