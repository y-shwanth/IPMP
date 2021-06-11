#include<bits/stdc++.h>
using namespace std;

struct node
{
   int data;
   struct node* left;
   struct node* right;
};

struct node* newnode(int data)
{
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}

bool getAncestors(node* root, int x, vector<int> &v)
{
    if(root == NULL)
    return false;
    
    if(root->data == x)
    return true;
    
    if(getAncestors(root->left, x, v) || getAncestors(root->right, x, v))
    {
        v.push_back(root->data);
        return true;
    }
    
    return false;
}

int main()
{
  struct node *root = newnode(1);
  root->left        = newnode(2);
  root->right       = newnode(3);
  root->left->left  = newnode(4);
  root->left->right = newnode(5);
  root->left->left->left  = newnode(7);
  
  vector<int> v;
  int x = 3;
  getAncestors(root, x, v);
  
  for(int i=0;i < v.size();i++)
  cout<<v[i]<<" ";
  
  getchar();
  return 0;
}
