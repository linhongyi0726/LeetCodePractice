# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        if not nums:
            return None
        mid = len(nums)//2
        node = TreeNode(nums[mid], self.sortedArrayToBST(nums[:mid]), self.sortedArrayToBST(nums[mid+1:]))
        return node

class Solution:
    def helper(self, nums, left, right):
        if left > right:
            return None
        mid = (left+right)//2
        node = TreeNode(nums[mid])
        print(node.val)
        node.left = self.helper(nums, left, mid-1)
        node.right = self.helper(nums, mid+1, right)
        return node

    def sortedArrayToBST(self, nums) -> TreeNode:
        return self.helper(nums, 0, len(nums)-1)
