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
Node* reverse(Node* head)
{
    if(head == NULL)
    {
        return head;
    }
    Node* lasthead = NULL;
    Node* ptr = head->next;
        
    while(ptr != NULL)
    {
        head->next = lasthead;
        lasthead = head;
        head = ptr;
        ptr = head->next;
    }
    head->next = lasthead;        
    return head;
}
void evenodd(Node* head)
{
    Node* evenhead = NULL;
    Node* oddhead = NULL;
    Node* ptr = head;
    Node* temp = NULL;
    while(ptr!= NULL)
    {
        if(ptr->data % 2 == 0)
        {
            temp = ptr->next;
            ptr->next = evenhead;
            evenhead = ptr;
            ptr = temp;
        }
        else
        {
            temp = ptr->next;
            ptr->next = oddhead;
            oddhead = ptr;
            ptr = temp;
        }
        
    }
    evenhead = reverse(evenhead);
    oddhead = reverse(oddhead);
    ptr = evenhead;
    head = ptr;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = oddhead;

    print(head);
    return;
}

int main()
{
    Node* head = NULL;
    push(&head,6);
    push(&head,7);
    push(&head,1);
    push(&head,4);
    push(&head,5);
    push(&head,10);
    push(&head,12);
    push(&head,8);
    push(&head,15);
    push(&head,17);
    
    evenodd(head);
    return 1;
}