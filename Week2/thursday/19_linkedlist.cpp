#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    char data;
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
void vowelfirst(Node* head)
{
    Node* vowelhead = NULL;
    Node* consohead = NULL;
    Node* ptr = head;
    Node* temp = NULL;
    while(ptr!= NULL)
    {
        if(ptr->data == 'a' || ptr->data == 'e' || ptr->data == 'i' || ptr->data == 'o' || ptr->data == 'u' || ptr->data == 'A' || ptr->data == 'E' || ptr->data == 'I' || ptr->data == 'O' || ptr->data == 'U')
        {
            temp = ptr->next;
            ptr->next = vowelhead;
            vowelhead = ptr;
            ptr = temp;
        }
        else
        {
            temp = ptr->next;
            ptr->next = consohead;
            consohead = ptr;
            ptr = temp;
        }
        
    }
    vowelhead = reverse(vowelhead);
    consohead = reverse(consohead);
    ptr = vowelhead;
    head = ptr;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = consohead;

    print(head);
    return;
}

int main()
{
    Node* head = NULL;
    push(&head,'i');
    push(&head,'b');
    push(&head,'p');
    push(&head,'U');
    push(&head,'q');
    push(&head,'r');
    push(&head,'A');
    push(&head,'S');
    push(&head,'e');
    push(&head,'t');
    
    vowelfirst(head);
    return 1;
}