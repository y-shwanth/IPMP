Node *copyList(Node *head) 
{
    unordered_map<Node*,Node*> mp;
    Node* x=head;
    while(x)
    {
        Node* orig=new Node(x->data);
        mp[x]=orig;
        x=x->next;
    }
    Node* ptr=head;
    Node* curr=NULL;
    while(ptr)
    {
        curr=mp[ptr];
        curr->next=mp[ptr->next];
        curr->arb=mp[ptr->arb];
        ptr=ptr->next;
    }
    return mp[head];
}