class Solution:
    def isPalindrome(self, s: str) -> bool:
        for char in s:
            if not char.isalnum():
                s = s.replace(char, '')
        s = s.lower()
        rev = s[::-1]
        if s == rev:
            return True
        return False


class Solution:
    def isPalindrome(self, s: str) -> bool:
        start = 0
        end = len(s) - 1
        while start <= end:
            if s[start].isalnum() and s[end].isalnum():
                if s[start].lower() == s[end].lower():
                    start += 1
                    end -= 1
                    continue
                return False
            if not s[start].isalnum():
                start += 1
            if not s[end].isalnum():
                end -= 1
        return True
