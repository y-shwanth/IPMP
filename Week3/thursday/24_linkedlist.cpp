#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};
 
void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node[(sizeof(Node))];
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(Node* node)
{
    while (node != NULL) 
    {
        cout<<node->data<<" ";
        node = node->next;
    }
}

void pairWiseSwap(Node* head)
{
    Node* temp = head;
    while (temp != NULL && temp->next != NULL) 
    {
        swap(temp->data, temp->next->data);
        temp = temp->next->next;
    }
}

int main()
{
    Node *head = NULL;
    push(&head,5);
    push(&head,4);
    push(&head,3);
    push(&head,2);
    push(&head,1);
    printList(head);
    pairWiseSwap(head);
    printList(head);

    return 1;
}