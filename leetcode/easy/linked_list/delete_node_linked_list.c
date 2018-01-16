/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>
#include <stdlib.h>

/* Link list node */
struct ListNode {
    int data;
    struct ListNode* next;
};

void deleteNode(struct ListNode* node) {
    struct ListNode* tmp = node->next;

    node->data = tmp->data;
    node->next = tmp->next;
    free(tmp);
}

void insertNode(struct ListNode** head, int new_data) {
    /* allocate node */
    struct ListNode* new_node = (struct ListNode*) malloc(sizeof(struct ListNode));

    new_node->data = new_data;        
    new_node->next = NULL;

    new_node->next = *head;
    *head = new_node;
}

void printList(struct ListNode *head) {
    struct ListNode *temp = NULL;
    
    temp = head;

    while( temp != NULL ) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main(void) {
    struct ListNode* head = NULL;

    insertNode(&head, 20);
    insertNode(&head, 4);
    insertNode(&head, 15);
    insertNode(&head, 85);

    printf("Given linked list\n");
    printList(head);    

    deleteNode(head);
    printf("\nDeleted one node\n");
    printList(head);

    return 0;
}
