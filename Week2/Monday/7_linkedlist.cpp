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

void removeloop(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        head->next = NULL;
        return;
    }
    Node* slowptr = head;
    Node* fastptr = head;
    while(fastptr && fastptr->next )
    {
        fastptr = fastptr->next->next;
        slowptr = slowptr->next;
        if(slowptr==fastptr)
        break;
    }
    if(slowptr == fastptr)
    {
        slowptr = head;
        if(slowptr == fastptr)
        {
            while(fastptr->next != slowptr)
            fastptr = fastptr->next;
        }
        else
        {
            while(fastptr->next != slowptr->next)
            {
                slowptr = slowptr->next;
                fastptr = fastptr->next;
            }
        }
        fastptr->next = NULL;
    }
}

void printList(Node* ptr)
{
    while (ptr != NULL) 
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
}

int main()
{
    Node* head = NULL;
    push(&head,5);
    push(&head,4);
    push(&head,3);
    push(&head,2);
    push(&head,1);

    head->next->next->next->next->next = head->next->next;
    removeloop(head);
    printList(head);
    return 1;
}