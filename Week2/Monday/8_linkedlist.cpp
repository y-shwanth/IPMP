/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head) {
        if(head == NULL)
        {
            return head;
        }
        ListNode* lasthead = NULL;
        ListNode* ptr = head->next;
        
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
    
    int midval(ListNode* head) {
        if(head->next == NULL)
        return head->val;
        ListNode* slowptr = head;
        ListNode* fastptr = head;
        
        while(fastptr != NULL && fastptr->next != NULL)
        {
            fastptr = fastptr->next->next;
            slowptr = slowptr->next;
        }
        
        return slowptr->val; 
    }
};