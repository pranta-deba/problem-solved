#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Inorder traversal: Left, Root, Right
void inorderTraversal(struct Node *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);     // Visit node
    inorderTraversal(root->left);  // Visit left subtree
    inorderTraversal(root->right); // Visit right subtree
}

int main()
{
    // Creating a sample binary tree
    /*
              1
             / \
            2   3
           / \
          4   5
    */

    struct Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Inorder Traversal: ");
    inorderTraversal(root);

    return 0;
}