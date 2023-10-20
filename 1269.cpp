// First time
/*
    The same idea but reduce the space complexity by reusing the dp array
    T: O(n^2)/S: O(n)
*/
class Solution {
public:
    int numWays(int steps, int arrLen) {
        int mxlen = min(steps / 2 + 1, arrLen);
        vector<int> dp(mxlen, 0);
        dp[0] = 1;
        int mod = 1e9 + 7;
        for (int i = 1; i <= steps; ++i) {
            auto prev = dp;
            for (int j = 0; j < mxlen; ++j) {
                dp[j] = prev[j];
                if (j + 1 < mxlen)
                    dp[j] = (dp[j] + prev[j + 1]) % mod;
                if (j - 1 >= 0)
                    dp[j] = (dp[j] + prev[j - 1]) % mod;
            }
        }
        return dp[0];
    }
};

/*
    DP
    dp[i][j] denote the ways we move i steps and stay at index j
    There are three cases we need to consider
    1. stay:
        dp[i][j] = dp[i-1][j]
    2. move to left:
        dp[i][j] = dp[i-1][j+1]
    3. move to right:
        dp[i][j] = dp[i-1][j-1]
    Then return dp[steps][0]

    *Notice just need to init array steps/2+1,
    because it is the max far position we can reach and still can move back to 0
    (NOT directly initial to arrLen, it will cause TLE)

    T: O(n^2)/S: O(n^2)
*/
class Solution {
public:
    int numWays(int steps, int arrLen) {
        int mxlen = min(steps / 2 + 1, arrLen);
        // If init dp[steps+1][arrLen] will TLE, because arrLen can be 1e6
        // vector<vector<int>> dp(steps + 1, vector<int>(arrLen, 0));
        vector<vector<int>> dp(steps + 1, vector<int>(mxlen, 0));
        dp[0][0] = 1;
        int mod = 1e9 + 7;
        for (int i = 1; i <= steps; ++i) {
            for (int j = 0; j < mxlen; ++j) {
                // stay
                dp[i][j] = dp[i - 1][j];
                // move left 1 step to position j
                if (j + 1 < mxlen)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % mod;
                // move right 1 step to position j
                if (j - 1 >= 0)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
            }
        }
        return dp[steps][0];
    }
};