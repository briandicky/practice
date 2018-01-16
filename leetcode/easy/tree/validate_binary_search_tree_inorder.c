/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool validateBST(struct TreeNode *root, struct TreeNode **prev) {
    if( !root )
        return true;

    // left 
    if( !validateBST(root->left, prev) )
        return false;

    // mid
    if( (*prev) != NULL && (*prev)->val >= root->val )
        return false;

    *prev = root;

    //right
    return validateBST(root->right, prev);
}

bool isValidBST(struct TreeNode *root) {
    struct TreeNode *prev = NULL;
    return validateBST(root, &prev);
}

struct TreeNode* newNode(int data) {
    struct TreeNode *node = (struct TreeNode*) 
        malloc( sizeof( struct TreeNode ) );

    node->val = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int main(void) {
    struct TreeNode *root;

    root = newNode(2);
    root->left = newNode(1);
    root->right = newNode(3);

    if( isValidBST(root) )
        printf("The tree is BST.\n");
    else 
        printf("The tree is not BST.\n");

    return 0;
}
