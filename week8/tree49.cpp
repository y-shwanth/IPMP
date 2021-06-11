#include <bits/stdc++.h>
using namespace std;
 
class node {
public:
    int data;
    node* left;
    node* right;
};
 
void bintree2listUtil(node* root, node** head, node** tail)
{
    if (root == NULL)
        return;
 
    node* left = root->left;
    node* right = root->right;
 
    bintree2listUtil(root->left, head, tail);
 
    if (*head == NULL) {
        *head = root;
    }
 
    root->left = *tail;
 
    if (*tail != NULL) {
        (*tail)->right = root;
    }
 
    *tail = root;
 
    bintree2listUtil(root->right, head, tail);
 
    return root;
}
 
node* bintree2list(node* root)
{
    // Base case
    if (root == NULL)
        return root;
 
    node* head = NULL;
    node* tail = NULL;
 
    bintree2listUtil(root, &head, &tail);
 
    return head;
}
 
node* newNode(int data)
{
    node* new_node = new node();
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return (new_node);
}
 
void printList(node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->right;
    }
}
 
int main()
{
    node* root = newNode(10);
    root->left = newNode(12);
    root->right = newNode(15);
    root->left->left = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);
 
    node* head = bintree2list(root);
 
    printList(head);
 
    return 0;
}
