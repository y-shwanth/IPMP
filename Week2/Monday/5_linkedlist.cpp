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

void deletelist(Node* head)
{
    Node* current = head;
    while(current != NULL)
    {
        head = head->next;
        cout<<"delete\n";
        free(current);
        current = head;
    }
    cout<<"==>list deleted";
}

int main()
{
    Node* head = NULL;
    push(&head,5);
    push(&head,4);
    push(&head,3);
    push(&head,2);
    push(&head,1);
    
    deletelist(head);
    return 1;
}