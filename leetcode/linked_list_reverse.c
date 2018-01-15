#include<stdio.h>
#include<stdlib.h>
 
/* Link list node */
struct ListNode
{
    int data;
    struct ListNode* next;
};
 
/* Function to reverse the linked list */
static void reverse(struct ListNode** head) {
    struct ListNode* current;
    struct ListNode* prev;
    struct ListNode* next;

    current = *head;
    prev = NULL;
    
    while( current != NULL ) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}
 
/* Function to push a node */
void push(struct ListNode** head, int new_data) {
    /* allocate node */
    struct ListNode* new_node =
            (struct ListNode*) malloc(sizeof(struct ListNode));
            
    /* put in the data  */
    new_node->data  = new_data;
                
    /* link the old list off the new node */
    new_node->next = (*head);    
        
    /* move the head to point to the new node */
    (*head)    = new_node;
}
 
/* Function to print linked list */
void printList(struct ListNode *head) {
    struct ListNode *temp = head;

    while(temp != NULL) {
        printf("%d  ", temp->data);    
        temp = temp->next;  
    }
}    
 
/* Driver program to test above function*/
int main()
{
    /* Start with the empty list */
    struct ListNode* head = NULL;
   
     push(&head, 20);
     push(&head, 4);
     push(&head, 15); 
     push(&head, 85);      
     
     printf("Given linked list\n");
     printList(head);    
     reverse(&head);                      
     printf("\nReversed Linked list \n");
     printList(head);    
     getchar();
}
