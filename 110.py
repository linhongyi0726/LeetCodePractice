# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def helper(self, root):
        if root == None:
            return 0, True
        l, lb = self.helper(root.left)
        r, rb = self.helper(root.right)
        if lb and rb and abs(l - r) <= 1:
            return max(l, r) + 1, True
        return -1, False

    def isBalanced(self, root):
        h, balance = self.helper(root)
        return balance
