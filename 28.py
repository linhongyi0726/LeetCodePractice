class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if needle == '':
            return 0
        L = len(haystack)
        l = len(needle)
        for i in range(L - l + 1):
            if haystack[i:i + l] == needle:
                return i
        return -1


class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        return haystack.find(needle)
