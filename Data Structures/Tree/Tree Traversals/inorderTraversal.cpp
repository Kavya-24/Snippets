#include <bits/stdc++.h>
using namespace std;

// A binary tree node
struct Node
{
    int data;
    struct Node *left, *right;
};

// Creating a new tree node
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Printing the nodes in inorder
void printInorder(struct Node *node)
{
    if (node == NULL)
        return;

    // left child
    printInorder(node->left);

    // data of node
    cout << node->data << " ";

    // right child
    printInorder(node->right);
}

int main()
{
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->right = newNode(6);
    cout << "\nInorder traversal of binary tree is \n";
    printInorder(root);
    return 0;
}