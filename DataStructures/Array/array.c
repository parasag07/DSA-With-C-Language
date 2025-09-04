#include <stdio.h>
#include <stdlib.h>

void size_of_array(int *arr){
    int size;
    // printf("Enter the size of array: \n");
    // scanf("%d", size);
    // int* arr = (int *)malloc(*size * sizeof(int));
    // for(i = 0; i < *size; i++) {
    //     printf("Enter element number %d: ", i + 1);
        // scanf("%d", &arr[i]);
    // }
    if(arr == NULL){
        printf("Array is empty.\n");
    }
    else{
        size = sizeof(*arr) / sizeof(arr[0]);
        printf("Size of array is: %d", size);
    }
}

void display_array(int *arr, int *size){
    if(*size == 0) {
        printf("Array is empty.\n");
    }
    else{
        printf("Contents of the array: \n");
        printf("[");
        if(*size == 1) {
            printf("%d", arr[0]);
        }
        else if(*size > 1) {
            for(int i = 0; i < *size - 1; i++) {
                printf("%d, ", arr[i]);
            }
            printf("%d", arr[*size - 1]);
        }
        printf("]\n");
    }
}

int *insert_element_at_index(int *arr, int *size){
    int index, element, i;
    
    
    if(*size == 0) {
        printf("Array is empty. Initializing with size 1.\n");
        printf("Enter the element to be inserted: ");
        scanf("%d", &element);
        arr = (int *)malloc(sizeof(int));
        arr[0] = element;
        *size = 1;
        return arr;
    }
    
    else{
        printf("Enter the index at which you want to insert element: ");
        scanf("%d", &index);
        if(index < 0 || index >= *size) {
            printf("Invalid index. Please enter a valid index between 0 and %d.\n", *size - 1);
            arr = insert_element_at_index(arr, size);
            return arr;
        }
        printf("Enter the element to be insert at index %d: ", index);
        scanf("%d", &element);
        
        
        int new_size = *size + 1;
        int *temp = realloc(arr, new_size * sizeof(int));
        if(temp == NULL) {
            // realloc failed, original data still in arr
            perror("Realloc failed");
            return arr;
        }
        for(i = *size; i > index; i--) { 
            arr[i] = arr[i - 1];
        }
        arr[index] = element;
        printf("Element %d inserted at index %d\n", element, index);
        *size = *size + 1;
        return arr;
    }
}

int *insert_element_at_end(int *arr, int *size){
    int index, element, i;
    
    
    if(*size == 0) {
        printf("Array is empty. Initializing with size 1.\n");
        printf("Enter the element to be inserted: ");
        scanf("%d", &element);
        arr = (int *)malloc(sizeof(int));
        arr[0] = element;
        printf("\nElement %d inserted.\n", element);
        *size = 1;
        return arr;
    }
    
    else{
        int *temp = realloc(arr, (*size + 1) * sizeof(int));
        if(temp == NULL) {
            // realloc failed, original data still in arr
            perror("Realloc failed");
            return arr;
        }
        arr = temp;
        printf("Enter the element to be insert at the end of the array: ");
        scanf("%d", &element);
        arr[*size] = element;
        *size = *size + 1;
        
        printf("\nElement %d inserted.\n", element);
        return arr;
        }
}

int *insert_multiple_elements(int *arr, int *size){
    int index, element, i, number_of_elements;
    
    printf("Enter the number of elements to be inserted: ");
    scanf("%d", &number_of_elements);
    
    if(*size == 0) {
        printf("Array is empty. Initializing with size %d.\n", number_of_elements);
        arr = (int *)malloc(number_of_elements * sizeof(int));
        *size = number_of_elements;
        for(i = 0; i < number_of_elements; i++) {
            printf("Enter element number %d: ", i + 1);
            scanf("%d", &element);
            arr[i] = element;
        }
        return arr;
    }
    
    else{
        int new_size = *size + number_of_elements;
        int *temp = realloc(arr, new_size * sizeof(int));
        if (temp == NULL) {
            // realloc failed, original data still in arr
            perror("Realloc failed");
            return arr;
        }
        arr = temp;
        
        for(i = 0; i < number_of_elements; i++) {
            printf("Enter element number %d: ", i + 1);
            scanf("%d", &element);
            arr[*size + i] = element;
        }
        *size = *size + number_of_elements;
        return arr;
    }
}

int *delete_element_at_index(int *arr, int *size){
    int index;
    if(*size == 0) 
    {
        printf("Array is empty. Cannot delete element.\n");
        return arr;
    }
    else
    {
        printf("Enter the index of the element you want to delete: \n");
        scanf("%d", &index);
        if(index < 0 || index >= *size) {
            printf("Invalid index. Please enter a valid index between 0 and %d.\n", *size - 1);
            delete_element_at_index(arr, size);
        }
        else{    
            for(int i = index; i < *size-1; i++){
                arr[i] = arr[i + 1];        
            }
            *size = *size - 1;
            printf("Element at index %d deleted\n", index);
            return arr;
        }
    }
}

int *delete_entire_array(int *arr, int *size){
    if(*size == 0) {
        printf("Array is already empty. Nothing to delete.\n");
        return arr;
    }
    else{   
        free(arr);
        *size = 0;
        printf("Entire array deleted\n");
        return arr;
    }
}

void menu(){
    int choice, index, cont, *arr = NULL, size = 0;
    
    do{
        printf("\nEnter your choice: \n");
        printf("1. Size of array\n");
        printf("2. Display the array\n");
        printf("3. Insert an element at a specific index\n");
        printf("4. Insert an element at the end of the array\n");
        printf("5. Insert multiple elements\n");
        printf("6. Delete an element at a specific index\n");
        printf("7. Delete the entire array\n");
        printf("0. Exit\n");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                size_of_array(arr);
                // printf("%d", size);
                break;
            
            case 2: 
                display_array(arr, &size);
                break;
            
            case 3: 
                arr = insert_element_at_index(arr, &size);
                display_array(arr, &size);
                break;
                
            case 4: 
                arr = insert_element_at_end(arr, &size);
                display_array(arr, &size);
                break;
                
            case 5: 
                arr = insert_multiple_elements(arr, &size);
                display_array(arr, &size);
                break;
                
            case 6: 
                arr = delete_element_at_index(arr, &size);
                if(size != 0){
                    display_array(arr, &size);
                }
                break;
                
            case 7: 
                arr = delete_entire_array(arr, &size);
                if(size != 0){
                    display_array(arr, &size);
                }
                break;
                
            case 0:
                printf("Exiting the program.\n");
                break;
                
            default:
                printf("Invalid choice. Please try again.\n");
                break;
            }
    }while (choice != 0);
    
    free(arr);
}

int main(){
    
    menu();
    
    return 0;
}