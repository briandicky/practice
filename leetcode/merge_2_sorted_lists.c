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

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if( !l1 )
        return l2;
    
    if( !l2 )
        return l1;

    struct ListNode *ret;
    struct ListNode *tmp;

    if( l1->val <= l2->val ) {
        ret = l1;
        l1 = l1->next;
    } 
    else {
        ret = l2;
        l2 = l2->next;
    }

    tmp = ret;

    while( l1 != NULL && l2 != NULL ) {
        if( l1->val <= l2->val ) {
            tmp->next = l1;
            l1 = l1->next;
        } 
        else {
            tmp->next = l2;
            l2 = l2->next;
        }

        tmp = tmp->next;
    }

    if( l1 != NULL )
        tmp->next = l1;

    if( l2 != NULL )
        tmp->next = l2;

    return ret;
}

void insertNode(struct ListNode **head, int new_data) {
    struct ListNode *new_node = 
        (struct ListNode*) malloc(sizeof(struct ListNode));

    new_node->val = new_data;
    new_node->next = NULL;

    new_node->next = *head;
    *head = new_node;
}

void printList(struct ListNode *head) {
    struct ListNode *temp;

    temp = head;
    while( temp != NULL ) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
}

int main(void) {
    struct ListNode *input1 = NULL;
    struct ListNode *input2 = NULL;
    struct ListNode *merge = NULL;

    insertNode(&input1, 4);
    insertNode(&input1, 2);
    insertNode(&input1, 1);

    insertNode(&input2, 4);
    insertNode(&input2, 3);
    insertNode(&input2, 1);
    
    printf("Given linked list 1:\n");
    printList(input1);
    printf("\nGiven linked list 2:\n");
    printList(input2);

    printf("\nAfter merging these two linked lists:\n");
    merge = mergeTwoLists(input1, input2);
    printList(merge);

    return 0;
}
