class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        x = {}
        for i, num in enumerate(nums):
            n = target - num
            if n in x:
                return [x[n], i]
            else:
                x[n] = i
