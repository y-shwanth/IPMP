/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

//QUES 9 - CONNECT LEVEL ORDER
class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL)
            return root;
        Node* temp;
        queue<Node*> q;
        q.push(root);
        while(q.empty() == false)
        {
            temp = q.front();
            q.pop();
            temp->next = q.front();
            if(temp->left != NULL)
                q.push(temp->left);
            if(temp->right != NULL)
                q.push(temp->right);
        }
        temp = root;
        while(temp != NULL)
        {
            temp->next = NULL;
            temp = temp->right;
        }
        return root;
    }
};
//QUES 7 - POPULATE INORDER
class Solution {
public:
    Node* temp = NULL;
    void func(Node* node)
    {
        if(node == NULL)
            return;
        func(node->left);
        temp->next = node;
        temp = node;
        func(node->right);
    }
    Node* connect(Node* root) {
        if(root == NULL)
            return root;
        func(root);
        return root;
    }
};



