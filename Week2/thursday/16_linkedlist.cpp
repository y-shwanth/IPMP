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

void mergeLL(Node* a, Node* b)
{
    if(a == NULL)
    {
        if(b == NULL)
        {
            return;
        }
        else
        {
            print(b);
            return;
        }
    }
    else if(b == NULL)
    {
        print(a);
        return;
    }
    Node* aptr = a;
    Node* bptr = b;
    Node* res = NULL;
    while(aptr!= NULL && bptr!= NULL)
    {
        if(aptr->data < bptr->data)
        {
            push(&res,aptr->data);
            aptr = aptr->next;
        }
        else
        {
            push(&res,bptr->data);
            bptr = bptr->next;
        }
    }
    while(aptr != NULL)
    {
        push(&res,aptr->data);
        aptr = aptr->next;
    }
    while(bptr != NULL)
    {
        push(&res,bptr->data);
        bptr = bptr->next;
    }

    res = reverse(res);;
    print(res);
    return ;
}

int main()
{
    Node* a = NULL;
    Node* b = NULL;
    push(&a,11);
    push(&a,10);
    push(&a,8);
    push(&a,7);
    push(&a,1);

    push(&b,15);
    push(&b,6);
    push(&b,5);
    push(&b,4);
    
    mergeLL(a,b);
    return 1;
}