#include <stdio.h>
#include <stdlib.h>

int main(){
    
    // Use of malloc
    // Malloc allocates the requested amount of memory malloc(n*sizeof())
    int* ptr;
    int i;
    
    ptr = (int *)malloc(3*sizeof(int));
    for(i=0;i<3;i++) {
        printf("Enter the value no %d of this array: \n", i);
        scanf("%d", &ptr[i]);
    }
    for(i=0;i<3;i++) {
        printf("The value at no %d of this array is: %d\n", i, ptr[i]);
    }
    
    
    return 0;
}