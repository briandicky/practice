#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left;
    struct node *right;
};

// A utility function to create a new BST node
struct node* newNode(int data) {
    struct node *node = (struct node*) malloc( sizeof( struct node ) );

    node->key = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// A utility function to do inorder traversal of BST
void inorder(struct node *root) {
    if( root != NULL ) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// A utility function to insert a new node with given key in BST
struct node* insert(struct node *root, int key) {
    // If the tree is empty, then return a new node
    if( root == NULL )
        return newNode(key);

    // otherwise, recursion down to the tree
    if( key < root->key )
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    // return the node pointer
    return root;
}

/* Given a non-empty binary search tree, return the node with minimum
 *    key value found in that tree. Note that the entire tree does not
 *       need to be searched. */
struct node* minValueNode(struct node *node) {
    struct node *current = node;

    // loop dow to find the leftmost leaf
    while( current->left != NULL )
        current = current->left;

    return current;
}

/* Given a binary search tree and a key, this function deletes the key
 *    and returns the new root */
struct node* deleteNode(struct node *root, int key) {
    // base case
    if( root == NULL )
        return root;

    // If the key to be deleted is samller/greater than the root's key,
    // then it lies in left/right subtree
    if( root->key > key )
        root->left = deleteNode(root->left, key);
    else if( root->key < key )
        root->right = deleteNode(root->right, key);
    // if key is same as root's key, then this is the node to be deleted
    else {
        // node with no child
        if(root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        // node with only one child
        else if( root->left == NULL ) {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if( root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        // node with two children
        else {
            // To get the inorder successor (smallest in the right subtree)
            struct node *temp = minValueNode(root->right);
            
            // copy the inorder successor's content to this node
            root->key = temp->key;

            // delete the inorder successor
            root->right = deleteNode(root->right, temp->key);
        }
    }

    return root;
}


int main(void) {
    /* Let us create following BST
           50
         /     \
        30      70
       /  \    /  \
     20   40  60   80 */

    struct node *root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder traversal of the given tree \n");
    inorder(root);

    printf("\n\nDelete 20\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    printf("\n\nDelete 30\n");
    root = deleteNode(root, 30);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    printf("\n\nDelete 50\n");
    root = deleteNode(root, 50);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    return 0;

    return 0;
}
