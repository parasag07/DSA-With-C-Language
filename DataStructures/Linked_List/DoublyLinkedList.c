#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node* prev;
    int data;
    struct node* next;
};

int size_of_list(struct node* head){
    int size = 0;
    if(head == NULL){
        return size;
    }
    else if(head->next == NULL){
        return 1;
    }
    else{
        struct node* temp = head;
        do{
            temp = temp->next;
            size++;
        }while(temp != NULL);
        return size;
    }
}

void traversal(struct node* head){
    if(head == NULL){
        printf("List is empty. Nothing to print!\n");
    }
    else{
        struct node* temp = head;
        printf("Elements of the list are: \n");
        do{
            printf("Element: %d\n", temp->data);
            temp = temp->next;
        }while(temp != NULL);
    }
}

struct node* insert_at_beginning(struct node* head){
    int data;
    printf("Enter data to insert: ");
    scanf("%d", &data);
    if(head == NULL){
        head = malloc(sizeof(struct node));
        head->prev = NULL;
        head->data = data;
        head->next = NULL;
    }
    else{
        struct node* new_node = malloc(sizeof(struct node));
        new_node->data = data;
        new_node->next = head;
        new_node->prev = NULL;
        head->prev = new_node;
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
        struct node* new_node = malloc(sizeof(struct node));
        printf("Enter data to insert: ");
        scanf("%d", &data);
        new_node->data = data;
        new_node->next = NULL;
        if(head->next == NULL){
            new_node->prev = head;
            head->next = new_node;
        }
        else{
            struct node* temp = head;
            do{
                temp = temp->next;
            }while(temp->next != NULL);
            new_node->prev = temp;
            temp->next = new_node;
        }
    }
    return head;
}

struct node* insert_in_between(struct node* head){
    if(head == NULL){
        printf("List is empty. Element will be inserted in beginning.\n");
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
                printf("Position entered is less than/equal to zero, Element will be inserted at the beginning.\n");
                head = insert_at_beginning(head);
            }
        }
        else if(pos >= size_of_list(head)){
            printf("Position entered either exceeds the size of list or is equal to it. Element will be inserted at end.\n");
            head = insert_at_end(head);
        }
        else{
            int data;
            struct node* temp = head;
            printf("Enter the data you want to insert: ");
            scanf("%d", &data);
            while(k < pos - 1){
                temp = temp->next;
                k++;
            }
            struct node* new_node = malloc(sizeof(struct node));
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
        printf("List is empty, nothing to delete.\n");
    }
    else{
        if(head->next == NULL){
            printf("Element deleted is: %d\n", head->data);
            struct node* temp = head;
            head = NULL;
            free(temp);
        }
        else{   
            struct node* temp = head;
            head = head->next;
            head->prev = NULL;
            printf("Element deleted is: %d\n", temp->data);
            free(temp);
        }
        if(head == NULL){
            printf("List is now empty after deletion.\n");
        }
        else{
            printf("List after deletion:\n");
            traversal(head);
        }
    }
    return head;
}

struct node* delete_at_end(struct node* head){
    if(head == NULL){
        printf("List is empty, nothing to delete.\n");
    }
    else{
        if(head->next == NULL){
            printf("Element deleted is: %d\n", head->data);
            struct node* temp = head;
            head = NULL;
            free(temp);
        }
        else if(head->next->next == NULL){
            printf("Element deleted is: %d\n", head->next->data);
            free(head->next);
            head->next = NULL;
        }
        else{   
            struct node* temp = head;
            do{
                temp = temp->next;
            }while(temp->next->next != NULL);
            printf("Element deleted is: %d\n", temp->next->data);
            free(temp->next);
            temp->next = NULL;
        }
        if(head == NULL){
            printf("List is now empty after deletion.\n");
        }
        else{
            printf("List after deletion:\n");
            traversal(head);
        }
    }
    return head;
}

struct node* delete_in_between(struct node* head){
    if(head == NULL){
        printf("List is empty, nothing to delete.\n");
    }
    else{
        if(head->next == NULL){
            printf("List has only one element to delete, hence it will be deleted.\n");
            printf("Element deleted is: %d\n", head->data);
            struct node* temp = head;
            head = NULL;
            free(temp);
        }
        else{
            int pos, k = 1;
            printf("Enter the position at which you want to delete the element: ");
            scanf("%d", &pos);
            if(pos <= 0){
                printf("Position entered is less than/equal to zero. Element will be delete from beginning.\n");
                head = delete_at_beginning(head);
            }
            else if(pos >= size_of_list(head)){
                printf("Position exceeds/is equal to the size of list. Element will be deleted from end.\n");
                head = delete_at_end(head);
            }
            else{
                struct node* temp = head;
                struct node* temp2 = head->next->next;
                do{
                    temp = temp->next;
                    temp2 = temp2->next;
                    k++;
                }while(k < pos - 1);
                printf("Element deleted is: %d\n", temp->next->data);
                free(temp->next);
                temp->next = temp2;
                temp2->prev = temp;
            }
        }
        if(head == NULL){
            printf("List is now empty after deletion.\n");
        }
        else{
            printf("List after deletion:\n");
            traversal(head);
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
        printf("6. Check is list is empty\n");
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