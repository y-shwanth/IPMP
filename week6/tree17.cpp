#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct node {
    int data;
    struct node *left, *right;
};
struct node* newNode(int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
  
    temp->data = data;
    temp->left = temp->right = NULL;
  
    return temp;
}

void leaf_node(node* temp)
{
    if(temp == NULL)
    return;
    leaf_node(temp->left);
    if(temp->left == NULL && temp->right == NULL)
    cout<<temp->data<<" ";
    leaf_node(temp->right);
}

void right_boundary(node* temp)
{
    if(temp->right == NULL)
    return;
    right_boundary(temp->right);
    cout<<temp->data<<" ";
}

void boundary_tra(node* root)
{
    struct node* temp = root;
    while(temp->left != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->left;
    }
    leaf_node(root);

    right_boundary(root);
}

int main()
{
    struct node* root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);
  
    boundary_tra(root);
  
    return 0;
}
