# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if not l1:
            return l2
        if not l2:
            return l1
        if l1.val < l2.val:
            l1.next = self.mergeTwoLists(l1.next, l2)
            return l1
        else:
            l2.next = self.mergeTwoLists(l2.next, l1)
            return l2


class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        tmp = ListNode()
        if not l1:
            return l2
        if not l2:
            return l1
        if l1.val < l2.val:
            tmp = l1
            tmp.next = self.mergeTwoLists(l1.next, l2)
        else:
            tmp = l2
            l2.next = self.mergeTwoLists(l2.next, l1)
        return tmp


class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        cur = ListNode(0)
        head = cur
        while l1 and l2:
            if l1.val < l2.val:
                cur.next = l1
                l1 = l1.next
            else:
                cur.next = l2
                l2 = l2.next
            cur = cur.next
        if not l1:
            cur.next = l2
        if not l2:
            cur.next = l1
        return head.next
