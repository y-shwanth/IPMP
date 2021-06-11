class Solution {
public:
    
    TreeNode *po(ListNode **head,int i,int j){
        if(i>j) 
          return NULL;
        TreeNode *a = new TreeNode(0);
        
        int mid = (i+j)/2;
    
        a->left = po(head,i,mid-1);
        a->val = (*head)->val;
        *head = (*head)->next;
        a->right = po(head,mid+1,j);
        return a;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode *p = head;
        int l = 0;  
        while(p!=NULL && l++>-1)
            p = p->next;
        return po(&head,0,l-1);
    }
};
