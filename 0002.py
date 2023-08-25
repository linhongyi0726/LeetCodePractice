class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode, carry=0) -> ListNode:
        if l1 == None:
            return l2
        if l2 == None:
            return l1
        sum = l1.val + l2.val + carry
        carry = sum // 10
        result = ListNode(sum % 10)
        if l1.next != None or l2.next != None or carry != 0:
            if l1.next == None:
                l1.next = ListNode(0)
            if l2.next == None:
                l2.next = ListNode(0)
            result.next = self.addTwoNumbers(l1.next, l2.next, carry)
        return result
