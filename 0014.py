class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        strs.sort()
        prefix = ''
        if len(strs) == 0:
            return prefix
        for char in strs[0]:
            if strs[-1].startswith(prefix + char):
                prefix = prefix + char
            else:
                break
        return prefix
