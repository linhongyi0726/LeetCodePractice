class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        d = {}
        maxlength = 0
        start = 0
        for i, char in enumerate(s):
            if char in d:
                move = d[char] + 1
                if move > start:
                    start = move
            d[char] = i
            total = i - start + 1
            if total > maxlength:
                maxlength = total
        return maxlength
