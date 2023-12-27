// First time
/*
    DP
    reduce space complexity

    T: O(n*k*target)/S: O(target)
*/
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<int> dp(target + 1, 0);
        int mod = 1e9 + 7;
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            vector<int> cur(target + 1, 0);
            // h means this time we throw
            for (int h = 1; h <= k; ++h) {
                for (int j = h; j <= target; ++j) {
                    // find the target that previous die throw, and it can combine to j
                    cur[j] = (cur[j] + dp[j - h]) % mod;
                }
            }
            dp = cur;
        }
        return dp[target];
    }
};

/*
    DP
    dp[i][j] denote the ways in i dice and j target

    T: O(n*k*target)/S: O(n*target)
*/
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        int mod = 1e9 + 7;
        for (int i = 1; i <= target; ++i) {
            if (i <= k)
                dp[1][i] = 1;
        }
        for (int i = 1; i <= n; ++i) {
            for (int h = 1; h <= k; ++h) {
                for (int j = h; j <= target; ++j) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - h]) % mod;
                }
            }
        }
        return dp[n][target];
    }
};

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        int mod = 1e9 + 7;
        for (int i = 1; i <= target; ++i) {
            if (i <= k)
                dp[1][i] = 1;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= target; ++j) {
                // for every target j, we need to sum up the previous die and its target is [1:j]
                for (int h = 1; h < j; ++h) {
                    // only calculate the number that can be thrown by die
                    if (h <= k)
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - h]) % mod;
                }
            }
        }
        return dp[n][target];
    }
};