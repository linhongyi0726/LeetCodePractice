class Solution:
    def romanToInt(self, s: str) -> int:
        roman = {'I': 1, 'V': 5, 'X': 10, 'L': 50,
                 'C': 100, 'D': 500, 'M': 1000}
        ans = 0
        previous = 0
        for char in s[::-1]:
            if roman[char] >= previous:
                ans = ans + roman[char]
            else:
                ans = ans - roman[char]
            previous = roman[char]
        return ans


class Solution:
    def romanToInt(self, s: str) -> int:
        roman = {'I': 1, 'V': 5, 'X': 10, 'L': 50,
                 'C': 100, 'D': 500, 'M': 1000}
        ans = 0
        for i in range(len(s)):
            if i < len(s) - 1 and roman[s[i]] < roman[s[i + 1]]:
                ans = ans - roman[s[i]]
            else:
                ans = ans + roman[s[i]]
        return ans
