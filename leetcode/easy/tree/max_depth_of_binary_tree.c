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

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode* root) {
   if( !root )
       return 0;

   int leftdepth = maxDepth(root->left);
   int rightdepth = maxDepth(root->right);

   if( leftdepth >= rightdepth )
       return leftdepth + 1;
   else 
       return rightdepth + 1;
}

struct TreeNode* newNode(int data) {
    struct TreeNode *node = 
        (struct TreeNode*) malloc(sizeof(struct TreeNode));

    node->val = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int main(void) {
    struct TreeNode *root;

    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Height/Depth of the tree is %d\n", maxDepth(root));

    return 0;
}
