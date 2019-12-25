class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        return mergeCut(0, lists.size() - 1, lists);
    }
    
    ListNode* mergeCut(int left, int right, vector<ListNode*>& lists) {
        if(left < right) {
            int mid = (left + right) / 2;
            return merge(mergeCut(left, mid, lists), mergeCut(mid + 1, right, lists));
        }
        return merge(lists[left], lists[right]);
    }
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if(l1 == l2) return l1;
        ListNode *dummy = new ListNode(0), *temp = dummy;
        ListNode *next1 = l1, *next2 = l2;
        while(next1 && next2) {
            if(next1 -> val < next2 -> val) {
                temp -> next = next1;
                temp = temp -> next;
                next1 = next1 -> next;
            }
            else {
                temp -> next = next2;
                temp = temp -> next;
                next2 = next2 -> next;
            };
        }
        temp -> next = next1 ? next1 : next2;
        return dummy -> next;
    }
};