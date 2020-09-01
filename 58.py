class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        strs = s.split()
        if len(strs) > 0:
            return len(strs[-1])
        else:
            return 0
