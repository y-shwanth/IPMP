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

void right_subtree(Node* root)
{
    if(root->left == NULL)
    {
        cout<<" is "<<root->data<<"\n";
        return;
    }
    right_subtree(root->left);
}

void search_tree(Node* root,Node* temp)
{
    int val = -1;
    while(root != temp)
    {
        if(root->data > temp->data)
        {
            val = root->data;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    cout<<" is "<<val<<"\n";
}

void inorder_successor(Node* root, Node* temp)
{
    if(temp->right == NULL)
    search_tree(root,temp);
    else
    right_subtree(temp->right);
}

int main()
{
    struct Node *root = NULL;
    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 22);
    root = insert(root, 4);
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 14);
    struct Node* temp = root->left->right->right;

    cout<<"inorder successor of "<<temp->data;
    inorder_successor(root,temp);
    return 1;
}
