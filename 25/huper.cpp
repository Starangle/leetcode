class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL)
            return NULL;
        int count = 0;
        ListNode* cur = head;
        
        while(cur && count < k) {
            cur = cur -> next;
            count++;
        }
        
        if(count == k) {
            ListNode *p1 = NULL, *p2 = head;
            while(count--) {
                ListNode* p3 = p2 -> next;
                p2 -> next = p1;
                p1 = p2;
                p2 = p3;
            }
            ListNode* sub = reverseKGroup(p2, k);
            head -> next = sub;
            return p1;
        }
        
        else return head;
    }
};