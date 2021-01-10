# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# Recursive
class Solution:
    def dfs(self, l, r):
        if not l and not r:
            return True
        if not l or not r or l.val != r.val:
            return False
        return self.dfs(l.left, r.right) and self.dfs(l.right, r.left)

    def isSymmetric(self, root: TreeNode) -> bool:
        return self.dfs(root, root)


# Iterative
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        stack = [root, root]
        while stack:
            r = stack.pop()
            l = stack.pop()
            if not l and not r:
                continue
            if not l or not r or l.val != r.val:
                return False
            stack.append(l.left)
            stack.append(r.right)
            stack.append(l.right)
            stack.append(r.left)
        return True
