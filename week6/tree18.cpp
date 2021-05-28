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

void leaf_node(node* temp,int &count)
{
    if(temp == NULL)
    return;
    leaf_node(temp->left,count);
    if(temp->left == NULL && temp->right == NULL)
    {
        ++count;
        cout<<temp->data<<" ";
    }
    leaf_node(temp->right,count);
}

int main()
{
    int count = 0;
    struct node* root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);
  
    leaf_node(root,count);
    cout<<"\n"<<count;    
    return 0;
}
