class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = [[]]
        for num in nums:
            for i in range(len(res)):
                res.append(res[i] + [num])
        return res


class Solution:
    def helper(self, nums, res, pos):
        for i in range(len(res)):
            res.append(res[i] + [nums[pos]])
        if pos == len(nums) - 1:
            return None
        return self.helper(nums, res, pos + 1)

    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = [[]]
        self.helper(nums, res, 0)
        return res


class Solution:
    def dfs(self, nums, index, path, res):
        res.append(path)
        for i in range(index, len(nums)):
            self.dfs(nums, i + 1, path + [nums[i]], res)
        return res

    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []
        self.dfs(nums, 0, [], res)
        return res


class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        res = []
        for i in range(2**n, 2**(n + 1)):
            bitmask = bin(i)[3:]
            res.append([nums[j] for j in range(n) if bitmask[j] == '1'])
        return res
