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

map<int,int> m;

void vertical_sum(node* root,int x)
{
    if(root == NULL)
    return;
    vertical_sum(root->left,x-1);
    m[x] = m[x] + root->data;
    vertical_sum(root->right,x+1);
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

    vertical_sum(root,0);

    map<int,int> :: iterator it;
    for(it = m.begin();it != m.end();it++)
    {
        cout<<"co ordinate "<<it->first;
        cout<<" "<<it->second<<"\n";
    }
    return 0;
}
