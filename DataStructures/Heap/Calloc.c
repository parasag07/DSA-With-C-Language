#include <stdio.h>
#include <stdlib.h>

int main()
{

    // Use of Calloc
    // Calloc allocates the requested amount of memory calloc(n, sizeof())
    // It assigns value 0 if no input is provided
    int *ptr;
    int n, i;

    printf("Enter the size of array: \n");
    scanf("%d", &n);
    ptr = (int *)calloc(n, sizeof(int));
    for (i = 0; i < n; i++)
    {
        printf("Enter the value index %d of this array: \n", i);
        scanf("%d", &ptr[i]);
    }
    for (i = 0; i < n; i++)
    {
        printf("The value at index %d of this array is: %d\n", i, ptr[i]);
    }

    free(ptr);

    return 0;
}