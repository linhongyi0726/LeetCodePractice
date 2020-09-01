# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        cur = ListNode(0)
        res = cur
        cur.next = head
        cur = cur.next
        while head:
            if cur.val == head.val:
                if head.next == None:
                    cur.next = None
                head = head.next
            else:
                cur.next = head
                cur = cur.next
                head = head.next
        return res.next


class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        cur = head
        while cur and cur.next:
            if cur.val == cur.next.val:
                cur.next = cur.next.next
            else:
                cur = cur.next
        return head
