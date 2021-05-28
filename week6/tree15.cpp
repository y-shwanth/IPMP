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

void del_node(node* temp)
{
    if(temp == NULL)
    return;
    del_node(temp->left);
    del_node(temp->right);

    cout<<"deleted "<<temp->data<<"\n";
    delete temp;
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
  
    del_node(root);    
    return 0;
}
