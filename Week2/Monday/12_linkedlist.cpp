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

void deletalter(Node* head)
{
    Node* ptr = head;
    Node* delptr = head->next;
    while(ptr != NULL && delptr != NULL)
    {
        ptr->next = delptr->next;
        free(delptr);
        ptr = ptr->next;
        if(ptr != NULL)
        delptr = ptr->next;
    }
    ptr = head;
    while(ptr != NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }

    return ;
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

    deletalter(head);
    return 1;
}