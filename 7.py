class Solution:
    def reverse(self, x: int) -> int:
        if x >= 0:
            ans = int(str(x)[::-1])
        else:
            ans = -1 * int(str(x)[:0:-1])
        if ans > 2**31 - 1 or ans < -2**31:
            return 0
        return ans


class Solution:
    def reverse(self, x: int) -> int:
        ans = 0
        if x >= 0:
            while x != 0:
                remain = x % 10
                x //= 10
                ans = ans * 10 + remain
        else:
            while x != 0:
                x = abs(x)
                remain = x % 10
                x //= 10
                ans = ans * 10 + remain
            ans = -1 * ans
        if ans > 2**31 - 1 or ans < -2**31:
            return 0
        return ans
