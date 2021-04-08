#include<bits/stdc++.h>
using namespace std;

bool flag = true;

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

Node* rotategrp(Node* head, int k)
{
    int count=1;
    Node* inihead = head;
    if(flag == false)
    {
        while(inihead->next != NULL && count<k)
        {
            inihead = inihead->next;
            ++count;
        }
        Node* kplus1node = inihead->next;
        if(kplus1node != NULL)
        {
            flag = true;
            inihead->next = rotategrp(kplus1node,k);
        }
        return head;
    }
    else
    {
        Node* lasthead = NULL;
        Node* ptr = head->next;
        while(ptr!= NULL && count < k)
        {
            head->next = lasthead;
            lasthead = head;
            head = ptr;
            ptr = head->next;
            ++count;
        }
        Node* kplus1node = head->next;
        head->next = lasthead;
        if(kplus1node != NULL)
        {
            flag = false;
            inihead->next = rotategrp(kplus1node,k);
        }
        return head;
    }



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

    head = rotategrp(head,3);
    print(head);
    return 1;
}