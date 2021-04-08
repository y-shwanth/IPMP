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

void rotatek(Node* head, int k)
{
    Node* ptr = head;
    Node* kplus1node = NULL;
    int count = 1;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
        ++count;
        if(count==k)
        {
            kplus1node = ptr->next;
            ptr->next = NULL;
            ptr = kplus1node;
        }
    }
    ptr->next = head;
    head = kplus1node;

    ptr = head;
    while(ptr!= NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }

    return;
}

int main()
{
    Node* head = NULL;
    push(&head,11);
    push(&head,10);
    push(&head,8);
    push(&head,7);
    push(&head,5);
    push(&head,3);
    push(&head,1);
    push(&head,0);

    rotatek(head,4);
    return 1;
}