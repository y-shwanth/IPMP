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

void printList(Node* node)
{
    while (node != NULL) 
    {
        cout<<node->data<<" ";
        node = node->next;
    }
    cout<<"\n\n";
}

void swapping(Node* temp1, Node* temp2)
{
    Node* a = temp1->next;
    Node* b = temp2->next;

    temp1->next = b;
    temp2->next = a;

    Node* temp = a->next;
    a->next = b->next;
    b->next = temp;
    return;
}

void swapkthnodes(Node* head, int k)
{
    int n = getsize(head);
    Node* ptr = head;
    Node* temp1;
    Node* temp2;
    int count = 1;
    while(ptr != NULL && count < (n-k+1))
    {
        if(count == (k-1))
        temp1 = ptr;
        if(count == (n-k))
        temp2 = ptr;

        ptr = ptr->next;
        ++count;
    }
    swapping(temp1,temp2);
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
    printList(head);
    
    swapkthnodes(head,2);
    printList(head);

    return 1;
}