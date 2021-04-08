#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
};
void push(Node** head_ref, char new_data) 
{
    Node* new_node = new Node();
    new_node->data = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref) = new_node; 
}
void print(Node* head)
{
    Node* ptr = head;
    while(ptr!= NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
}
void one2three(Node* head)
{
    Node* zerohead = NULL;
    Node* onehead = NULL;
    Node* twohead = NULL;
    Node* ptr = head;
    Node* temp = NULL;
    while(ptr!= NULL)
    {
        if(ptr->data == 0)
        {
            temp = ptr->next;
            ptr->next = zerohead;
            zerohead = ptr;
            ptr = temp;
        }
        else if(ptr->data == 1)
        {
            temp = ptr->next;
            ptr->next = onehead;
            onehead = ptr;
            ptr = temp;
        }
        else
        {
            temp = ptr->next;
            ptr->next = twohead;
            twohead = ptr;
            ptr = temp;
        }
        
    }
    ptr = zerohead;
    head = ptr;
    int flag = 1;
    while(ptr!= NULL && flag != -1)
    {
        if(ptr->next == NULL && flag == 1)
        {
            ptr->next = onehead;
            flag = 2;
        }
        if(ptr->next == NULL && flag == 2)
        {
            ptr->next = twohead;
            flag = -1;
        }
        ptr = ptr->next;
    }

    print(head);
    return;
}

int main()
{
    Node* head = NULL;
    push(&head,1);
    push(&head,0);
    push(&head,2);
    push(&head,0);
    push(&head,2);
    push(&head,1);
    push(&head,1);
    
    one2three(head);
    return 1;
}