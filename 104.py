# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# DFS
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if not root:
            return 0
        return 1 + max(self.maxDepth(root.left), self.maxDepth(root.right))


class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if not root:
            return 0
        l = self.maxDepth(root.left)
        r = self.maxDepth(root.right)
        if l > r:
            return l + 1
        else:
            return r + 1


# BFS
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if not root:
            return 0
        height = 0
        queue = [root]
        while queue:
            height += 1
            for i in range(len(queue)):
                if queue[0].left:
                    queue.append(queue[0].left)
                if queue[0].right:
                    queue.append(queue[0].right)
                del queue[0]
        return height
