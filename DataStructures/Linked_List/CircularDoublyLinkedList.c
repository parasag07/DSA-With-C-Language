#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node* prev;
    int data;
    struct node* next;
};

void traversal(struct node* head){
    if(head == NULL){
        printf("List is empty! Nothing to print.\n");
    }
    else{
        struct node* temp = head;
        printf("The elements in the list are: \n");
        do{
            printf("Element: %d\n", temp->data);
            temp = temp->next;
        }while(temp != head);
    }
}

void condition_traversal(struct node* head){
    if(head != NULL){
        traversal(head);
    }
    else{
        printf("List is now empty.\n");
    }
}

int size_of_list(struct node* head){
    int size = 0;
    if(head ==NULL){
        return size;
    }
    else{
        struct node* temp = head;
        do{
            size++;
            temp = temp->next;
        }while(temp != head);
        return size;
    }
}

struct node* insert_at_beginning(struct node* head){
    int data;
    struct node* new_node = malloc(sizeof(struct node));
    printf("Enter the element to enter: ");
    scanf("%d", &data);
    if(head == NULL){
        new_node->data = data;
        new_node->next = new_node;
        new_node->prev = new_node;
        head = new_node;
    }
    else{
        struct node* temp = head->prev;
        new_node->data = data;
        new_node->next = head;
        new_node->prev = temp;
        head->prev = new_node;
        temp->next = new_node;
        head = new_node;
    }
    return head;
}

struct node* insert_at_end(struct node* head){
    if(head == NULL){
        head = insert_at_beginning(head);
    }
    else{
        int data;
        struct node* temp = head->prev;
        struct node* new_node = malloc(sizeof(struct node));
        printf("Enter the element to enter: ");
        scanf("%d", &data);
        new_node->data = data;
        new_node->next = head;
        new_node->prev = temp;
        temp->next = new_node;
        head->prev = new_node;
    }
    return head;
}

struct node* insert_in_between(struct node* head){
    if(head == NULL){
        printf("List is empty. Element will be inserted at beginning.\n");
        head = insert_at_beginning(head);
    }
    else{
        int pos, k = 1;
        printf("Enter the position at which you want to enter the element: ");
        scanf("%d", &pos);
        if(pos <= 0 || pos == 1){
            if(pos == 1){
                head = insert_at_beginning(head);
            }
            else{
                printf("Position Invalid! Element will be inserted at the beginning.\n");
                head = insert_at_beginning(head);
            }
        }
        else if(pos >= size_of_list(head)){
            printf("Position exceeds/is equal to the size of list. Element will be inserted at the end.\n");
            head = insert_at_end(head);
        }
        else{
            int data;
            struct node* temp = head;
            struct node* new_node = malloc(sizeof(struct node));
            while(k < pos - 1){
                temp = temp->next;
                k++;
            }
            printf("Enter the data to insert: ");
            scanf("%d", &data);
            new_node->data = data;
            new_node->next = temp->next;
            new_node->prev = temp;
            temp->next->prev = new_node;
            temp->next = new_node;
            
        }
    }
    return head;
}

void is_empty(struct node* head){
    if(head == NULL){
        printf("List is empty.\n");
    }
    else{
        printf("List is not empty.\n");
    }
}

struct node* delete_at_beginning(struct node* head){
    if(head == NULL){
        printf("List is empty. Nothing to delete.\n");
    }
    else if(head->next == head){
        struct node* temp = head;
        printf("Element %d deleted from the beginning.\n", head->data);
        head = NULL;
        free(temp);
        condition_traversal(head);
    }
    else if(head->next->next == head){
        struct node* temp = head;
        printf("Element %d deleted from the beginning.\n", head->data);
        head = head->next;
        head->next = head;
        head->prev = head;
        free(temp);
        condition_traversal(head);
    }
    else{
        struct node* temp = head;
        printf("Element %d deleted from the beginning.\n", temp->data);
        temp->prev->next = temp->next;
        head = head->next;
        head->prev = temp->prev;
        free(temp);
        condition_traversal(head);
    }
    return head;
}

struct node* delete_at_end(struct node* head){
    if(head == NULL){
        printf("List is empty. Nothing to delete.\n");
    }
    else if(head->next == head){
        struct node* temp = head;
        printf("Element %d deleted from the end.\n", head->data);
        head = NULL;
        free(temp);
        condition_traversal(head);
    }
    else if(head->next->next == head){
        struct node* temp = head;
        printf("Element %d deleted from the end.\n", head->next->data);
        head->next = head;
        head->prev = head;
        free(temp->next);
        condition_traversal(head);
    }
    else{
        struct node* temp = head->prev;
        printf("Element %d deleted from the end.\n", temp->data);
        temp->prev->next = head;
        head->prev = temp->prev;
        free(temp);
        condition_traversal(head);
    }
    return head;
}

struct node* delete_in_between(struct node* head){
    if(head == NULL){
        printf("List is empty. Nothing to delete.\n");
    }
    else{
        int pos, k = 1;
        printf("Enter the position at which you want to delete the element: ");
        scanf("%d", &pos);
        if(pos <= 0 || pos == 1){
            if(pos == 1){
                head = delete_at_beginning(head);
            }
            else{
                printf("Position Invalid! Element will be deleted from the beginning.\n");
                head = delete_at_beginning(head);
            }
        }
        else if(pos >= size_of_list(head)){
            printf("Position entered exeeds/is equal to the size of list. Element will be deleted from the end.\n");
            head = delete_at_end(head);
        }
        else{
            struct node* temp = head;
            struct node* temp2 = head->next;
            while(k < pos - 1){
                temp = temp->next;
                temp2 = temp2->next;
                k++;
            }
            printf("Element %d deleted from position %d.\n", temp2->data, pos);
            temp->next->next->prev = temp;
            temp->next = temp->next->next;
            free(temp2);
            condition_traversal(head);
        }
    }
    return head;
}

void menu(){
    int choice;
    struct node* head = NULL;
    do{
        printf("\nEnter your preferred choice:\n");
        printf("1. Print the current size of the list\n");
        printf("2. Linked list traversal\n");
        printf("3. Insert element at the beginning\n");
        printf("4. Insert element at the end\n");
        printf("5. Insert element in between\n");
        printf("6. Check if list is empty\n");
        printf("7. Delete element at the beginning\n");
        printf("8. Delete element at the end\n");
        printf("9. Delete element in between\n");
        printf("0. Exit\n");
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                printf("Size of the list is: %d\n", size_of_list(head));
                break;
                
            case 2:
                traversal(head);
                break;
                
            case 3:
                head = insert_at_beginning(head);
                traversal(head);
                break;
                
            case 4:
                head = insert_at_end(head);
                traversal(head);
                break;
                
            case 5:
                head = insert_in_between(head);
                traversal(head);
                break;
                
            case 6:
                is_empty(head);
                break;
                
            case 7:
                head = delete_at_beginning(head);
                break;
                
            case 8:
                head = delete_at_end(head);
                break;
                
            case 9:
                head = delete_in_between(head);
                break;
                
            case 0:
                printf("Exiting...\n");
                break;
                
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while(choice != 0);
}

int main(){
    menu();
    printf("Program terminated successfully.\n");
    return 0;
}