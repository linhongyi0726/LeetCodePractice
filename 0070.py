class Solution:
    def climbStairs(self, n: int) -> int:
        first = 1
        second = 2
        if n == 1:
            return first
        elif n == 2:
            return second
        elif n > 2:
            for i in range(n - 2):
                third = first + second
                first = second
                second = third
            return third


class Solution:
    def climbStairs(self, n: int) -> int:
        dp = [0] * (n + 1)
        dp[0] = 1
        dp[1] = 1
        for i in range(2, n + 1):
            dp[i] = dp[i - 1] + dp[i - 2]
        return dp[n]
