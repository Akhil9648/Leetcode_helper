# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeTwoLists(self, list1, list2):
        """
        :type list1: Optional[ListNode]
        :type list2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        ans=ListNode(-1)
        ptr=ans
        ptr1,ptr2=list1,list2
        while(ptr1 and ptr2):
            if ptr1.val<ptr2.val:
                curr=ListNode(ptr1.val)
                ptr.next=curr
                ptr=curr
                ptr1=ptr1.next
            else:
                curr=ListNode(ptr2.val)
                ptr.next=curr
                ptr=curr
                ptr2=ptr2.next
        while(ptr1):
            curr=ListNode(ptr1.val)
            ptr.next=curr
            ptr=curr
            ptr1=ptr1.next
        while(ptr2):
            curr=ListNode(ptr2.val)
            ptr.next=curr
            ptr=curr
            ptr2=ptr2.next
        return ans.next