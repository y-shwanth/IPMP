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
    
    bool isPalindrome(ListNode* head) {
        if(head->next == NULL)
        return true;
        ListNode* slowptr = head;
        ListNode* fastptr = head;
        ListNode* lastslowptr = NULL;
        ListNode* midptr = NULL;
        while(fastptr != NULL && fastptr->next != NULL)
        {
            fastptr = fastptr->next->next;
            lastslowptr = slowptr;
            slowptr = slowptr->next;
        }
        if(fastptr != NULL)
        {
            midptr = slowptr;
            slowptr = slowptr->next;
        }
        lastslowptr->next = NULL;
        ListNode* secondhalfptr = reverse(slowptr);
        
        while(head!=NULL && secondhalfptr!=NULL)
        {
            if(head->val != secondhalfptr->val)
            return false;
            head = head->next;
            secondhalfptr =secondhalfptr->next;
        }
        return true;
        
    }
};