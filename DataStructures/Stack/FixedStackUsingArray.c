#include <stdio.h>
#define MAX 100 

void print_stack(int stack[], int *size)
{
    int i;
    if (*size == 0)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Stack elements are(top to bottom):\n");
        printf("[");
        for (i = *size - 1; i >= 0; i--)
        {
            if(i == 0){
                printf("%d", stack[i]);
            }                
            else{
                printf("%d, ", stack[i]);
            }

        }
        printf("]\n");
    }
}

void is_empty(int stack[], int *size)
{
    if (*size == 0)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Stack is not empty!\n");
    }
}

void is_full(int stack[], int *size)
{
    if (*size == MAX)
    {
        printf("Stack is full!\n");
    }
    else
    {
        printf("Stack is not full!\n");
    }
}

void push(int stack[], int *size)
{
    int element;
    if(*size == MAX)
    {
        printf("Stack is full!\n");
    }
    else{
        printf("Enter the element to be pushed onto the stack: ");
        scanf("%d", &element);
        stack[*size] = element;
        (*size)++;
        printf("Element %d pushed onto the stack.\n", element);
    }
}

void pop(int stack[], int *size)
{
    if(*size == 0)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Popped element: %d\n", stack[*size - 1]);
        (*size)--;
    }
}

void peek(int stack[], int *size)
{
    if (*size != 0)
    {
        printf("Top element: %d\n", stack[*size - 1]);
    }
    else
    {
        printf("Stack is empty!\n");
    }
}

void bottom_element(int stack[], int *size)
{
    if(*size == 0)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Bottom element: %d\n", stack[0]);
    }
}

void size_of_stack(int *size)
{
    printf("Current size of stack: %d\n", *size);
}

void menu()
{
    int choice, size = 0, stack[MAX];
    
    do
    {
        printf("\nChoose the operation you want to perform:\n");
        printf("1. Print stack\n");
        printf("2. Check if stack is empty\n");
        printf("3. Check if stack is full\n");
        printf("4. Push an element onto the stack\n");
        printf("5. Pop an element from the stack\n");
        printf("6. Peek at the top element of the stack\n");
        printf("7. Get the bottom element of the stack\n");
        printf("8. Print the current size of the stack\n");
        printf("9. Exit\n");
        scanf("%d", &choice);
        
        switch (choice)
        {
        case 1:
            print_stack(stack, &size);
            break;
            
        case 2:
            is_empty(stack, &size);
            break;
            
        case 3:
            is_full(stack, &size);
            break;
            
        case 4:
            push(stack, &size);
            print_stack(stack, &size);
            break;
            
        case 5:
            pop(stack, &size);
            print_stack(stack, &size);
            break;
            
        case 6:
            peek(stack, &size);
            break;
            
        case 7:
            bottom_element(stack, &size);
            break;

        case 8:
            size_of_stack(&size);
            break;
            
        case 9:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (choice != 9);
}

int main()
{
    menu();
    printf("Program terminated successfully.\n");
    return 0;
}