#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void LinkedListTraversal(struct Node *ptr) {
    while(ptr != NULL){
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main(){
    
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    
    // Allocate memory for the nodes in Linked List in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    
    // Link first and second nodes
    head->data = 10;
    head->next = second;
    
    // Link second and third nodes
    second->data = 20;
    second->next = third;
    
    // Link third and fourth nodes
    third->data = 30;
    third->next = fourth;
    
    // Terminate the list at the fourth node
    fourth->data = 40;
    fourth->next = NULL;
    
    LinkedListTraversal(head);
    
    return 0;
}