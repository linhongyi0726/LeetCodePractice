# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# BFS
class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        res = []
        if not root:
            return res
        queue = [root]
        while queue:
            res.insert(0, [queue[i].val for i in range(len(queue))])
            for i in range(len(queue)):
                if queue[0].left:
                    queue.append(queue[0].left)
                if queue[0].right:
                    queue.append(queue[0].right)
                del queue[0]
        return res
