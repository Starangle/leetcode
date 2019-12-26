/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {

public:
    ListNode* helper(ListNode* root,ListNode* previous){
           // 不能用dummy 节点
           ListNode* res = root;
           
           while(root){
               ListNode* next = root->next;
               root->next=dummy->next;
               dummy->next=root;
               root=next;
           }
           if(flag!=false)previous->next = dummy->next; 
           if(flag == false){new_head = dummy->next; flag = true;}
           dummy->next= NULL;
           return res;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        new_head = head;
    
         ListNode* p = head;
        // int cnt=0;
        // while(p){
        //     cnt++;
        //     p=p->next;
        // }

    //    p = head;
        ListNode* previous = NULL;
        while(p){
            ListNode* head_temp = p;

            int temp = k-1;
            while(p&&temp--){
                p = p->next;
            }

            if(p){
                ListNode* next = p->next;
                p->next=NULL;
                ListNode* q = helper(head_temp,previous);
                q->next = next;
                p=next;
                previous= q; 
            }else break;

        }
        return new_head;


    }
    ListNode* dummy = new ListNode(-1);
    ListNode* new_head;
    bool flag = false;
};