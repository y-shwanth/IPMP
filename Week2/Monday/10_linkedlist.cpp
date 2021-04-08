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

void intersect_sorted(Node* head, Node* head2)
{
    Node* ptr1 = head;
    Node* ptr2 = head2;
    while(ptr1 != NULL || ptr2 != NULL)
    {
        if(ptr1->data > ptr2->data)
        ptr2 = ptr2->next;
        else if(ptr1->data < ptr2->data)
        ptr1 = ptr1->next;
        else
        {
            cout<<ptr1->data<<" ";
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }
}


int main()
{
    Node* head = NULL;
    Node* head2 = NULL;
    push(&head,8);
    push(&head,7);
    push(&head,6);
    push(&head,5);
    push(&head,4);
    push(&head,3);

    push(&head2,11);
    push(&head2,10);
    push(&head2,8);
    push(&head2,7);
    push(&head2,5);
    push(&head2,3);
    push(&head2,1);
    push(&head2,0);
    
    intersect_sorted(head,head2);
    return 1;
}