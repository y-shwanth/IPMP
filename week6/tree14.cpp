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

bool all_leaves(node* root)
{
    int flag=-1,level=0;
    queue<node*> oldq,newq;
    struct node* temp;
    oldq.push(root);
    while(true)
    {
        temp = oldq.front();
        oldq.pop();
        if(temp->left == NULL && temp->right == NULL)
        {
            cout<<temp->data<<" data "<<flag<<" "<<level<<"\n";
            if(flag < 0)
            flag = level;
            else
            {
                if(flag != level)
                {
                    return false;
                }
            }
        }
        if(temp->left != NULL)
        newq.push(temp->left);
        if(temp->right != NULL)
        newq.push(temp->right);

        if(oldq.empty() == true)
        {
            if(newq.empty() == true)
            break;
            oldq = newq;
            newq = queue<node*>();
            ++level;
            cout<<level<<"\n";
        }
    }
    return true;
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


    if(all_leaves(root))
    cout<<"Yes all same level";
    else
    cout<<"No all not same level";
    return 0;
}
