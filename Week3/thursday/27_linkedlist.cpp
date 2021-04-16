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

Node* reverseList(Node* head)
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

void eveodd(Node* head)
{
    Node* oddhead = NULL;
    Node* evenhead = NULL;
    Node* ptr = head;
    Node* temp = NULL;
    int count = 1;
    while(ptr != NULL)
    {
        if(count %2 == 0)
        {
            temp = ptr->next;
            ptr->next = evenhead;
            evenhead = ptr;
            ptr = temp;
        }
        else
        {
            temp = ptr->next;
            ptr->next = oddhead;
            oddhead = ptr;
            ptr = temp;
        }
        ++count;
    }
   
    oddhead = reverseList(oddhead);
    evenhead = reverseList(evenhead);

    ptr = oddhead;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = evenhead;
    head = oddhead;
    printresult(head);
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

    eveodd(head);
    return 1;
}