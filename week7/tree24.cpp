#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


struct Node {
    int data;
    Node *left, *right;
};

struct Node* newNode(int data) 
{ 
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node); 
} 

struct Node* insert(struct Node* node, int data) 
{ 
    if (node == NULL) 
    return(newNode(data)); 
    
    else
    { 
        if (data <= node->data) 
        node->left = insert(node->left, data); 
        else
        node->right = insert(node->right, data); 
        return node;
    } 
} 

void min_in_BST(Node* root)
{
    if(root->left == NULL)
    {
        cout<<"minimum "<<root->data<<"\n";
        return;
    }
    min_in_BST(root->left);
}

int main()
{
    struct Node* root = NULL; 
    root = insert(root, 4); 
    insert(root, 2);
    insert(root, 1);
    insert(root, 3);
    insert(root, 6);
    insert(root, 5); 

    min_in_BST(root);
    return 1;
}
