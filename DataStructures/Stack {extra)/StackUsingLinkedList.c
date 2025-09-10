#include <stdio.h>
#include <stdlib.h>

// Define the Node structure for the stack linked list
struct Node
{
    int data;          // Data stored in the node
    struct Node *next; // Pointer to the next node
};

void printStack(struct Node *ptr)
{
    printf("Content of your stack is: \n");
    if (ptr == NULL)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("Element: %d\n", ptr->data);
            ptr = ptr->next; // Move to the next node
        }
    }
}

struct Node *CreateStack()
{
    struct Node *sp = NULL;
    printf("Stack Created.\n");
    printStack(sp);
    return sp;
}

void push(struct Node **top, int value)
{
    struct Node *newNode = malloc(sizeof(struct Node)); // Allocate memory for new node
    if (!newNode)
    {
        printf("Stack Overflow! Cannot push element.\n");
        return;
    }
    else
    {
        newNode->data = value; // Assign the value to new node
        newNode->next = *top;  // Link new node to current top
        *top = newNode;        // Update top to new node
    }
}

void pop(struct Node **top)
{
    struct Node *head; // Temporary pointer to top node
    head = *top;
    if (head == NULL)
    {
        printf("Stack is Empty! Nothing to pop.\n");
    }
    else
    {
        printf("Popped element: %d\n", head->data);
        *top = head->next;
        free(head); // Free the popped node
    }
}

void isEmpty(struct Node *ptr)
{
    if (ptr == NULL)
    {
        printf("The stack is Empty!\n");
    }
    else
    {
        printf("The stack is not Empty!\n");
    }
}

void Peek(struct Node *top)
{
    if (top == NULL)
    {
        printf("Stack is Empty! Nothing to display.\n");
    }
    else
    {
        printf("Top element: %d\n", top->data);
    }
}

void BottomElement(struct Node *s)
{
    if (s == NULL)
    {
        printf("Stack is Empty! Nothing to Show.\n");
    }
    else
    {
        while (s->next != NULL) // Traverse till last node
        {
            s = s->next;
        }
        printf("Bottom element: %d\n", s->data);
    }
}

int menu()
{
    int choice;
    printf("\nEnter 1 if you want to create a new Stack\n");
    printf("Enter 2 if you want to push an element\n");
    printf("Enter 3 if you want to pop the last element\n");
    printf("Enter 4 if you want to return the top element without popping it\n");
    printf("Enter 5 if you want to return the bottom most element\n");
    printf("Enter 6 if you want to check if the stack is empty\n");
    printf("Enter 7 if you want to print the stack.\n");
    printf("Enter 0 to Exit the program\n");
    scanf("%d", &choice);
    return choice;
}

int main()
{
    int value, choice;
    struct Node *top = NULL;

    do
    {
        choice = menu();
        switch (choice)
        {
        case 1:
            top = CreateStack();
            break;

        case 2:
            printf("Enter the element to push:\n");
            scanf("%d", &value);
            push(&top, value);
            printStack(top);
            break;

        case 3:
            pop(&top);
            printStack(top);
            break;

        case 4:
            Peek(top);
            break;

        case 5:
            BottomElement(top);
            break;

        case 6:
            isEmpty(top);
            break;

        case 7:
            printStack(top);
            break;

        case 0:
            printf("Exiting the program.\n");
            break;

        default:
            printf("Invalid choice entered! Enter a valid choice.\n");
            break;
        }
    } while (choice != 0);

    return 0;
}