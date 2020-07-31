class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        L = 0
        R = len(nums)
        while R > L:
            M = (L + R) // 2
            if nums[M] == target:
                return M
            elif nums[M] < target:
                L = M + 1
            elif nums[M] > target:
                R = M
        return L


class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        L = 0
        R = len(nums) - 1
        while R >= L:
            M = (L + R) // 2
            if nums[M] == target:
                return M
            elif nums[M] < target:
                L = M + 1
            elif nums[M] > target:
                R = M - 1
        return L
