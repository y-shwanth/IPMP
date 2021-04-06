/*struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=1; ListNode* temp = NULL;
        ListNode* nptr = head;
        ListNode* ptr = head;
        
        while(count!=n)
        {
            ptr = ptr->next;
            ++count;
        }
        if(count== n && ptr->next == NULL)
        {
            head = head->next;
            return head;
        }
        ptr = ptr->next;
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
            nptr = nptr->next;
        }
        temp = nptr->next;
        nptr->next = temp->next;
        return head;
    }
};