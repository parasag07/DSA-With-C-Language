#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

int size_of_list(struct node* head){
    int size = 0;
    struct node* temp = head;
    if(head == NULL){
        return size;
    }
    else{
        do{
            temp = temp->next;
            size++;
        }while(temp != head);
        return size;
    }
}

void traversal(struct node* head){
    struct node* temp = head;
    if(head == NULL){
        printf("List is empty.\n");
    }
    else{
        printf("The elements in the list are:\n");
        do{
            printf("Element: %d\n", temp->data);
            temp = temp->next;
        }while(temp != head);
    }
}
          
struct node* insert_at_beginning(struct node* head){
    int data;
    struct node* ptr = head;
    printf("Enter data to insert: \n");
    scanf("%d", &data);
    if(head == NULL){
        head = (struct node*)malloc(sizeof(struct node));
        head->data = data;
        head->next = head;
        return head;
    }
    else{    
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = data;
        new_node->next = head;
        head = new_node;
        do{
            ptr = ptr->next;
        }while(ptr->next != head->next);
        ptr->next = head;
        return head;
    }
}

struct node* insert_at_end(struct node* head){
    struct node* ptr = head;
    if(head == NULL){
        head = insert_at_beginning(head);
        return head;
    }
    else if(ptr->next == head){
        int data;
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        printf("Enter data to insert: \n");
        scanf("%d", &data);
        new_node->data = data;
        new_node->next = head;
        ptr->next = new_node;
        return head;
    }
    else{    
        int data;
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        printf("Enter data to insert: \n");
        scanf("%d", &data);
        do{
            ptr = ptr->next;
        }while(ptr->next != head);
        new_node->data = data;
        new_node->next = head;
        ptr->next = new_node;
        ptr = new_node;
        return head;
    }
}

struct node* insert_in_between(struct node* head){
    if(head == NULL){
        printf("List is empty, element will be inserted at beginning\n");
        head = insert_at_beginning(head);
        return head;
    }
    else if (head->next == head){
        head = insert_at_end(head);
        return head;
    }
    else{    
        int data, position, k = 1;
        printf("Enter position where you want to insert data: \n");
        scanf("%d", &position);
        if(position > size_of_list(head)){
            printf("Position exceeds the size of list, element will be inserted at end\n");
            head = insert_at_end(head);
            return head;
        }
        else if (position <= 0){
            printf("Invalid position, element will be inserted at beginning\n");
            head = insert_at_beginning(head);
            return head;
        }
        else{    
            printf("Enter data to insert: \n");
            scanf("%d", &data);
            struct node* new_node = (struct node*)malloc(sizeof(struct node));
            struct node* ptr = head;
            new_node->data = data;
            while(k < position - 1 && ptr->next != head){
                ptr = ptr->next;
                k++;
            }
            new_node->next = ptr->next;
            ptr->next = new_node;
            return head;
        }
    }
}

void is_empty(struct node* head){
    if(head == NULL){
        printf("List is empty\n");
    }
    else{
        printf("List is not empty\n");
    }
}

struct node* delete_at_beginning(struct node* head){
    struct node* temp = head;
    struct node* ptr = head;
    if(head == NULL){
        printf("List is empty, nothing to delete.\n");
    }
    else if(head->next == head){
        free(head);
        head = NULL;
    }
    else{
        head = temp->next;
        do{
            ptr = ptr->next;
        }while(ptr->next != temp);
        ptr->next = head;
        free(temp);
        if(head != NULL){
            traversal(head);
        }
        else{
            printf("List is now empty.\n");
        }
    }
    return head;
}

struct node* delete_at_end(struct node* head){
    struct node* temp = head;
    if(head == NULL){
        printf("List is empty, nothing to delete.\n");
    }
    else if(head->next == head){
        free(head);
        head = NULL;
    }
    else{
        do{
           temp = temp->next;
        }while(temp->next->next != head);
        
        free(temp->next);
        temp->next = head;
        if(head != NULL){
            traversal(head);
        }
        else{
            printf("List is now empty.\n");
        }
    }
    return head;
}

struct node* delete_in_between(struct node* head){
    int k = 1, position;
    struct node* temp = head;
    if(head == NULL){
        printf("List is empty, nothing to delete.\n");
    }
    else{
        printf("Enter the position of the elememt which you want to delete:\n");
        scanf("%d", &position);
        if(position > size_of_list(head)){
            printf("Position exceeds the size of list, element will be deleted from the end.\n");
            head = delete_at_end(head);
        }
        else if (position == 1){
        head = delete_at_beginning(head);
        return head;
        }
        else if(position == size_of_list(head)){
            printf("Position is same as the size of list, element will be deleted from the end.\n");
            head = delete_at_end(head);
        }
        else if (position <= 0){
            printf("Invalid position, element will be deleted from the beginning.\n");
            head = delete_at_beginning(head);
        }
        else{    
            do{
                temp = temp->next;
                k++;
            }while(k != position - 1);
            temp->next = temp->next->next;
            if(head != NULL){
                traversal(head);
            }
            else{
                printf("List is now empty.\n");
            }
        }
    }
    return head;
}

void menu(){
    int choice;
    struct node* head = NULL;
    do{
        printf("Enter your preferred choice:\n");
        printf("1. Print the current size of array\n");
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