#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

void printStack(struct stack *s)
{
    int i;
    printf("\nContent of your stack is: \n");
    for (i =s->top; i >= 0; i--)
    {
        printf("%d\n", s->arr[i]);
    }
}

struct stack* CreateStack()
{
    int size;
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    printf("Enter the size of stack\n");
    scanf("%d", &sp->size);
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    printStack(sp);
    return sp;
}

void push(struct stack *s, int value)
{
    if (s->top == s->size - 1)
    {
        printf("Stack is Overflowing! Cannot push element.\n");
    }
    else
    {
        s->top++;
        s->arr[s->top] = value;
    }
}

void pop(struct stack *s)
{
    if (s->top == -1)
    {
        printf("Stack is Empty! Nothing to pop.\n");
    }
    else
    {
        printf("Popped element: %d", s->arr[s->top]);
        s->arr[s->top] = 0;
        s->top--;
    }
}

void Peek(struct stack *s, int pos)
{
    if (pos > (s->size - 1))
    {
        printf("Given position is more than the size of the stack.\n");
    }
    else if(pos > (s->top)){
        printf("There is no value present at the given position.\n");
    }
    else
    {
        printf("Value at position %d is: %d\n", pos, s->arr[pos]);
    }
}

void isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        printf("The stack is Empty!\n");
    }
    else
    {
        printf("The stack is not Empty!\n");
    }
}

void isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        printf("The stack is Full!\n");
    }
    else
    {
        printf("The stack is not Full!\n");
    }
}

void TopElement(struct stack *s)
{
    if (s->top == -1)
    {
        printf("Stack is Empty! Nothing to display.\n");
    }
    else
    {
        printf("Top element: %d", s->arr[s->top]);
    }
}

void BottomElement(struct stack *s)
{
    if (s->top == -1)
    {
        printf("Stack is Empty! Nothing to pop.\n");
    }
    else
    {
        printf("Bottom element: %d", s->arr[0]);
    }
}

int menu()
{
    int choice;
    printf("\nEnter 1 if you want to create a new Stack\n");
    printf("Enter 2 if you want to push an element\n");
    printf("Enter 3 if you want to pop the last element\n");
    printf("Enter 4 if you want to get value at given positio from the top\n");
    printf("Enter 5 if you want to check if the stack is empty\n");
    printf("Enter 6 if you want to check if the stack is full\n");
    printf("Enter 7 if you want to return the top element without popping it\n");
    printf("Enter 8 if you want to return the bottom most element\n");
    scanf("%d", &choice);
    return choice;
}

int main()
{
    int value, pos, choice;

    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 100;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    choice = menu();

    switch (choice)
    {
    case 1:
        s = CreateStack();
        break;
    case 2:
        printf("Enter the element to push:\n");
        scanf("%d", &value);
        push(s, value);
        break;
    case 3:
        pop(s);
        break;

    case 4:
        printf("Enter the position at which you want the value:\n");
        scanf("%d", &pos);
        Peek(s, pos);
        break;

    case 5:
        isEmpty(s);
        break;

    case 6:
        isFull(s);
        break;

    case 7:
        TopElement(s);
        break;

    case 8:
        BottomElement(s);
        break;

    default:
        break;
    }

    if(choice != 1)
    {
        printStack(s);
    }

    return 0;
}