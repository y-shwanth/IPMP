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

void double_tree(node* root)
{
    if(root == NULL)
    return;
    double_tree(root->left);
    double_tree(root->right);

    struct node* temp = root->left;
    struct node* new_left = newNode(root->data);
    root->left = new_left;
    new_left->left = temp;
}

void print_tree(node* root)
{
    if(root == NULL)
    return;
    print_tree(root->left);
    cout<<root->data<<" ";
    print_tree(root->right);
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


    double_tree(root);
    print_tree(root);
    return 0;
}
