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

void func(Node* head, Node* head2, int d)
{
    Node* ptr1 = head;
    Node* ptr2 = head2;
    for(int i=0;i<d;i++)
    {
        if(ptr1 == NULL)
        return;
        ptr1 = ptr1->next;
    }
    while(ptr1 != NULL && ptr2 != NULL)
    {
        if(ptr1->data == ptr2->data)
        {
            cout<<ptr1->data<<"\n";
            return;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return ;
}

void intersecpoint(Node* head, Node* head2)
{
    Node* ptr = head;
    int count=1,count2=1,d;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
        ++count;
    }
    ptr = head2;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
        ++count2;
    }
    if(count>count2)
    {
        d = count-count2;
        func(head,head2,d);
    }
    else
    {
        d = count2-count;
        func(head2,head,d);
    }
    return;
}

int main()
{
    Node* head = NULL;
    Node* head2 = NULL;
    push(&head,6);
    push(&head,5);
    push(&head,4);
    push(&head,3);
    push(&head,2);
    push(&head,1);

    push(&head2,10);
    push(&head2,9);
    head2->next->next = head->next->next->next->next;
    
    intersecpoint(head,head2);
    return 1;
}