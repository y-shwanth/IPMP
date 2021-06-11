#include<stdio.h>
#include<stdlib.h>
  
struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

int countNodes(struct Node *head);
struct Node* sortedListToBSTRecur(struct Node **head_ref, int n);
  
struct Node* sortedListToBST(struct Node *head)
{
    int n = countNodes(head);
    return sortedListToBSTRecur(&head, n);
}
 
struct Node* sortedListToBSTRecur(struct Node **head_ref, int n)
{
    if (n <= 0)
        return NULL;
  
    struct Node *left = sortedListToBSTRecur(head_ref, n/2);
  
    struct Node *root = *head_ref;
  
    root->prev = left;
    *head_ref = (*head_ref)->next;
    root->next = sortedListToBSTRecur(head_ref, n-n/2-1);
  
    return root;
}
  
int countNodes(struct Node *head)
{
    int count = 0;
    struct Node *temp = head;
    while(temp)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
  
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
  
    new_node->data  = new_data;

    new_node->prev = NULL;
  
    new_node->next = (*head_ref);
  
    if((*head_ref) !=  NULL)
      (*head_ref)->prev = new_node ;
  
    (*head_ref)    = new_node;
}

void printList(struct Node *node)
{
    while (node!=NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
  
void preOrder(struct Node* node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->prev);
    preOrder(node->next);
}
  
int main()
{
    struct Node* head = NULL;
  
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
  
    printf("Given Linked List\n");
    printList(head);
  
    struct Node *root = sortedListToBST(head);
    printf("\n PreOrder Traversal of constructed BST \n ");
    preOrder(root);
  
    return 0;
}
