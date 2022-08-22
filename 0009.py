class Solution:
    def isPalindrome(self, x: int) -> bool:
        return str(x) == str(x)[::-1]


class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        else:
            reverse = 0
            num = x
            while x != 0:
                reverse = reverse * 10 + x % 10
                x //= 10
            return num == reverse


class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0 or x % 10 == 0 and x != 0:
            return False
        else:
            reverse = 0
            while x > reverse:
                reverse = reverse * 10 + x % 10
                x //= 10
            if x == reverse:
                return True
            if x == reverse // 10:
                return True
