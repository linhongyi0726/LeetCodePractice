class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        return n * (n + 1) // 2 - sum(nums)


class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        for num in range(len(nums) + 1):
            if num not in nums:
                return num
