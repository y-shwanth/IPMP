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

void kfromroot(node* root,int k)
{
    cout<<"note : Kth level doesn't exist then last existing lvel will be printed\n\n";
    struct node* temp;
    queue<node*> oldq,newq;
    oldq.push(root);
    for(int i=1;i<k;i++)
    {
        while(oldq.empty() == false)
        {
            temp= oldq.front();
            oldq.pop();
            if(temp->left != NULL)
            newq.push(temp->left);
            if(temp->right != NULL)
            newq.push(temp->right);
        }
        oldq = newq;
        newq = queue<node*>();
    }
    while(oldq.empty() == false)
    {
        temp = oldq.front();
        cout<<temp->data<<" ";
        oldq.pop();
    }
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

    kfromroot(root,3);
    
    return 0;
}
