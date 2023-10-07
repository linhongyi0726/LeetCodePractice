// First time
/*
    the product of n -> i*(n-i)
    when i = n/2, it will be the max product (means >= n itself), so we need to break it
    (n/2)*(n/2) >= n -> when n>=4, we need to break it
    It means the final answer must only contain 2 and 3, and we want at most 3

    T: O(n)/S: O(1)
    -----
    Or we can observe it, there is a regular pattern

    2: 1*1
    3: 1*3
    ---
    4: 2*2
    5: 3*2
    6: 3*3
    ---
    7: 3*2*2
    8: 3*3*2
    9: 3*3*3
    ---
    10: 3*3*2*2
    11: 3*3*3*2
    12: 3*3*3*3

    T: O(1)/S: O(1)
*/
class Solution {
public:
    int integerBreak(int n) {
        if (n == 2)
            return 1;
        else if (n == 3)
            return 2;
        else if (n == 4)
            return 4;
        // only break integer when it > 4
        int ret = 1;
        while (n > 4) {
            ret *= 3;
            n -= 3;
        }
        // the remain integer (maybe 2, 3, 4)
        ret *= n;
        return ret;
    }
};

class Solution {
public:
    int integerBreak(int n) {
        if (n == 2)
            return 1;
        else if (n == 3)
            return 2;
        else if (n % 3 == 1)
            return 4 * pow(3, (n - 4) / 3);
        else if (n % 3 == 2)
            return 2 * pow(3, (n - 2) / 3);
        else  // n % 3 == 0
            return pow(3, n / 3);
    }
};

/*
    DP
    dp[i] denote the max product in integer i
    Break integer to two integer and choose using itself or using its max product (dp[j])
    if we only choose its max product will fail
    e.g.
    dp[i] = max(dp[i], dp[j]*dp[i-j])
    4 = 2+2 -> dp[2]*dp[2] = 1*1 < 2*2

    T: O(n^2)/S: O(n)
*/
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i / 2; ++j) {
                dp[i] = max(dp[i], max(j, dp[j]) * max(i - j, dp[i - j]));
            }
        }
        return dp[n];
    }
};