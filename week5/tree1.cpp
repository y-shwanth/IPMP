#include <bits/stdc++.h>
using namespace std;

class node 
{ 
    public:
    int data; 
    node* left; 
    node* right; 
}; 

node* newNode(int data) 
{ 
    node* Node = new node();
    Node->data = data; 
    Node->left = NULL; 
    Node->right = NULL; 
          
    return(Node); 
} 

int size(Node *node)
{
    if(node == NULL)
    return 0;
    else
    return (size(node->left) + 1 + size(node->right));
}

int main() 
{ 
    node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->left->left->right = newNode(6); 
    root->left->left->left = newNode(7); 
    root->left->right->left = newNode(8); 
    root->left->right->right = newNode(9); 
  
      
    cout << "Size of the tree is " << size(root); 
    return 0; 
} 
