class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        sum = nums[0]
        maxvalue = nums[0]
        for i in range(1, len(nums)):
            tmp = sum + nums[i]
            if nums[i] > tmp:
                sum = nums[i]
            else:
                sum = tmp
            if sum > maxvalue:
                maxvalue = sum
        return maxvalue


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        sum = nums[0]
        maxvalue = nums[0]
        for i in range(1, len(nums)):
            tmp = sum + nums[i]
            sum = max(tmp, nums[i])
            maxvalue = max(sum, maxvalue)
        return maxvalue


# Dynamic Programming
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        dp = [0] * len(nums)
        dp[0] = nums[0]
        for i in range(1, len(nums)):
            dp[i] = max(nums[i], dp[i - 1] + nums[i])
        maxvalue = max(dp)
        return maxvalue
