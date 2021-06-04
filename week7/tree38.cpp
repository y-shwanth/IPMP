#include <bits/stdc++.h>
using namespace std;
 
class Node {
public:
    int data;
    Node *left, *right;
};
 
Node* newNode(int item)
{
    Node* temp = new Node();
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
void Greater_BST(Node* root)
{
        int sum = 0;
        stack<Node*> st;
        Node* node = root;
         
        while(!st.empty() || node != NULL )
        {
            while(node != NULL){
                st.push(node);
                node = node->right;
            }
          
            node = st.top();
            st.pop();
            sum += node->data;
            node->data = sum;
           
            node = node->left;
        }
}

void inorder(Node* root)
{
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
Node* insert(Node* node, int data)
{
    if (node == NULL)
        return newNode(data);
 
    if (data <= node->data)
        node->left = insert(node->left, data);
    else
        node->right = insert(node->right, data);
 
    return node;
}

int main()
{  
    Node* root = NULL;
    root = insert(root, 8);
    insert(root, 5);
    insert(root, 2);
    insert(root, 7);
    insert(root, 12);
    insert(root, 9);
    insert(root, 15);
 
    Greater_BST(root);
 
    inorder(root);
 
    return 0;
}
