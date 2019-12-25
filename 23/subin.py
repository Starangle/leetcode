# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        n=len(lists)
        if n==0:return None
        if n==1:return lists[0]
        elif n==2:
            l1,l2=lists
            # init
            res=ListNode(None)
            x=res
            # merge
            while l1 and l2:
                if l1.val<l2.val:
                    x.next=ListNode(l1.val)
                    l1=l1.next
                else:
                    x.next=ListNode(l2.val)
                    l2=l2.next
                x=x.next
            ll=l1 if l1 else l2
            while ll:
                x.next=ListNode(ll.val)
                ll=ll.next
                x=x.next
            return res.next
        else:
            l1=self.mergeKLists(lists[:n//2])
            l2=self.mergeKLists(lists[n//2:])
            return self.mergeKLists([l1,l2])
