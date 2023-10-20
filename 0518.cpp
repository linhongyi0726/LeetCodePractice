// First time
/*
    It looks like unbounded knapsack problem,
    but because we need to find the combinations, it will let us count duplication
    -> treat it a variation of 0/1 knapsack, just can pick various times (less then the amount/coin)
    T: O(n^3)/S: O(n)
    -----
    Optimization
    Actually we just need to count 1 time ith coins,
    because we already computed dp[i-coin] -> here must including multiple ith coins, we just need to add one
    T: O(n^2)/S: O(n)
*/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int coin : coins) {
            auto prev = dp;
            for (int i = 1; i <= amount; ++i) {
                dp[i] = 0;
                for (int j = 0; j <= i / coin; ++j) {
                    dp[i] += prev[i - j * coin];
                }
            }
        }
        return dp[amount];
    }
};

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int coin : coins) {
            // traverse from back to front to avoid overriding previous loop status
            for (int i = amount; i >= 1; --i) {
                // Notice to count the amount of using coin from 1,
                // because using 0 times is dp[i] itself (means the previous status)
                for (int j = 1; j <= i / coin; ++j) {
                    dp[i] += dp[i - j * coin];
                }
            }
        }
        return dp[amount];
    }
};

// Optimization
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int coin : coins) {
            for (int i = 1; i <= amount; ++i) {
                if (i >= coin)
                    dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
};

// classic 0/1 knapsack
// T: O(n^2)/S: O(n^2)
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = 1;
            for (int j = 1; j <= amount; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (j >= coins[i - 1])
                    dp[i][j] += dp[i][j - coins[i - 1]];
            }
        }
        return dp[n][amount];
    }
};

/*
    WRONG!!
    unbounded knapsack -> WA
    because the status transfer just plus, it will count twice
    e.g.
    [1, 2, 5]
    dp[1] = '1'+dp[0] -> {1}
    dp[2] = '1'+dp[1] -> {1,1}
            '2'+dp[0] -> {2}
    dp[3] = '1'+dp[2] -> {1,1,1}, {1,2}
            '2'+dp[1] -> {2,1} the same combinations!!
*/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= amount; ++i) {
            for (int coin : coins) {
                if (i >= coin)
                    dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
};