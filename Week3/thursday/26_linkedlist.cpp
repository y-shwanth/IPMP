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

int getsize(Node* node)
{
    int size = 0;
    while (node != NULL)
    {
        node = node->next;
        size++;
    }
    return size;
}

void printresult(Node *node)
{
    while(node != NULL) 
    {
        cout<<node->data<<" ";
        node = node->next;
    }
    cout<<"\n";
}

void deletemn(Node* head, int m, int n)
{
    int count = 1;
    Node* ptr = head;
    while(ptr != NULL)
    {
        if(count == m)
        break;
        ptr = ptr->next;
        ++count;
    }
    if(ptr == NULL)
    return;
    Node* start = ptr;
    ptr = ptr->next;
    Node* temp = NULL;
    for(count=0; count<n;count++)
    {
        temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
    start->next = ptr;

    return;
}

int main()
{
    Node *head = NULL;
    push(&head,8);
    push(&head,7);
    push(&head,6);
    push(&head,5);
    push(&head,4);
    push(&head,3);
    push(&head,2);
    push(&head,1);
    printresult(head);

    deletemn(head,2,3);
    printresult(head);
    return 1;
}