/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode **head, int n) {
    if( n < 1 ) 
        return *head;

    struct ListNode *first = NULL;
    struct ListNode *second = NULL;
    struct ListNode *temp = NULL;
    int step = 0;

    first = *head;
    second = *head;

    while(step < n) {
        first = first->next;
        step++;
    }

    if( first == NULL ) {
        temp = *head;
        *head = (*head)->next;
        free(temp);

        return *head;
    }

    while( first->next != NULL ) {
        first = first->next;
        second = second->next;
    }

    temp = second->next;
    second->next = temp->next;
    free(temp);

    return *head;
}

void insertNode(struct ListNode **head, int new_data) {
    struct ListNode *new_node = (struct ListNode*) malloc(sizeof(struct ListNode));

    new_node->val = new_data;
    new_node->next = NULL;

    new_node->next = *head;
    *head = new_node;
}

void printList(struct ListNode *head) {
    struct ListNode *tmp = NULL;

    tmp = head;

    while(tmp != NULL) {
        printf("%d ", tmp->val);
        tmp = tmp->next;
    }
}

int main(void) {
    struct ListNode *head = NULL;
    int n = 5;

    insertNode(&head, 5);
    insertNode(&head, 4);
    insertNode(&head, 3);
    insertNode(&head, 2);
    insertNode(&head, 1);

    printf("Given linked list\n");
    printList(head);

    printf("\nAfter removing the %dth node from end of list\n", n);
    printList(removeNthFromEnd(&head, n));

    return 0;
}
