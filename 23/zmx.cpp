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

    ListNode* mergeTwo(ListNode* a, ListNode* b){
        
        ListNode* p =a, * q = b;
        ListNode* dummy= new ListNode(-1);
        ListNode * cur = dummy;
        while(p&&q){
            if(p->val<=q->val){
                cur->next= p;
                cur = cur->next;
                p = p->next;

            } else{
                cur->next = q;
                cur = cur->next;
                q = q->next;
            }
        }
        while(p){
            cur->next = p;
            cur=cur->next;
            p = p->next;
        }
        while(q){
            cur->next = q;
            cur=cur->next;
            q = q->next;
        }
        cur->next = NULL;
        return dummy->next;

    }

    int lengthList(ListNode* a){
        int cnt=0;
        while(a){
            cnt++;
            a=a->next;
        }
        return cnt;
    }





    ListNode* mergeKLists(vector<ListNode*>& lists) {

           if(lists.size()==0) return NULL;
           if(lists.size()==1) return lists[0];
        
          // vector<ListNode*> temp = sortLists(lists);
          // if(temp.size()<2)return NULL;
           vector<ListNode*> res;
           vector<ListNode*> temp(lists.begin(),lists.end());

        //   ListNode*  res= mergeTwo(temp[0],temp[1]);
        
        while(temp.size()>=2){
            int size = temp.size();
           for(int i = 0 ; i < size ; i+=2){ if( i+1 < size ) res.push_back(mergeTwo(temp[i],temp[i+1])); else res.push_back(temp[i]);}
           temp = res;
           res.clear();
        }

        return res[0];
    }

};