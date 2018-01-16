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

bool validateBST(struct TreeNode *root, int minVal, int maxVal) {
    if( !root )
        return true;

    if( root->val <= minVal )
        return false;

    if( root->val >= maxVal )
        return false;

    return validateBST( root->left, minVal, root->val) && 
        validateBST( root->right, root->val, maxVal );
}

bool isValidBST(struct TreeNode *root) {
    return validateBST( root, INT_MIN, INT_MAX );
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
