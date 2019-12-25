# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        if k<2:
            return head

        prehead=ListNode(None)
        prehead.next=head
        result=prehead
        pl=prehead
        
        while True:
            tp,count=pl,0
            while tp.next and count<k:
                count+=1
                tp=tp.next
            if count<k:
                break

            for c in range(k//2):
                p1,p2=pl,pl
                for i in range(c):
                    p1=p1.next
                for i in range(k-c-1):
                    p2=p2.next
                if p1.next is p2:
                    tmp=p2.next
                    p2.next=p2.next.next
                    tmp.next=p1.next
                    p1.next=tmp
                else:
                    p1.next.next,p2.next.next=p2.next.next,p1.next.next
                    p1.next,p2.next=p2.next,p1.next
            
            tmp=result.next
            while tmp:
                print(tmp.val)
                tmp=tmp.next

            count=0
            while count<k:
                pl=pl.next
                count+=1
        return result.next
