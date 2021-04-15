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

void addzeroes(Node **head1, Node **head2)
{
    int h1 = getsize(*head1);
    int h2 = getsize(*head2);
    if(h1 == h2)
    return;
    
    int diff = abs(h1 - h2);
    if(h1>h2)
    while(diff>0)
    {
        push(head2,0);
        --diff;
    }
    else
    while(diff>0)
    {
        push(head1,0);
        --diff;
    }
}

void addlinkedlist(Node *head1, Node *head2, int* carry, Node **result)
{
    int sum = 0;
    if(head1 != NULL)
    {
        addlinkedlist(head1->next,head2->next,carry,result);
        sum = head1->data + head2->data + *carry;
        *carry = sum/10;  
        sum = sum % 10;

        push(result,sum);
    }
    return;
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

int main()
{
    Node *head1 = NULL, *head2 = NULL, *result = NULL;
    push(&head1,9);
    push(&head1,9);
    push(&head1,9);
    printresult(head1);

    push(&head2,8);
    push(&head2,1);

    addzeroes(&head1,&head2);
    printresult(head2);
    int carry = 0;

    push(&head1,0);
    push(&head2,0);
    addlinkedlist(head1,head2,&carry,&result);
    printresult(result);
    return 1;
}