// Third time
/*
    DP
    T: O(nm)/S: O(n)
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int coin : coins) {
                if (coin <= i && dp[i - coin] != INT_MAX)
                    dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};


// Second time
/*
    DP
    Bottom-up
    T: O(n*m)/S:(m)
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < dp.size(); ++i) {
            for (int coin : coins) {
                if (i >= coin && dp[i-coin] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i-coin]+1);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};


// First time
/*
    DP problem
    ex. coins = [1,2,5], amount = 11
    dp[11] = min(dp[11-1]+1, dp[11-2]+1, dp[11-5]+1) -> Take one for each coins

    *Notice the int overflow because of "dp[i-coin]+1", we can initialize dp vector by amount+1 to avoid it
    Because the smallest coin is one dollar, the maximum coin number is "amount"
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for (int i = 1; i < amount+1; ++i) {
            for (int coin : coins) {
                if (i >= coin)
                    dp[i] = min(dp[i], dp[i-coin]+1);
            }
        }
        return dp[amount] == amount+1 ? -1 : dp[amount];
    }
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for (int coin : coins) {
            for (int i = coin; i < amount+1; ++i)
                dp[i] = min(dp[i], dp[i-coin]+1);
        }
        return dp[amount] == amount+1 ? -1 : dp[amount];
    }
};

/*
    Or we can initialize dp vector by INT_MAX
    But we should add if condition to filter unused dp[i] (it's still INT_MAX)
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i < amount+1; ++i) {
            for (int coin : coins) {
                if (i >= coin && dp[i-coin] != INT_MAX)
                    dp[i] = min(dp[i], dp[i-coin]+1);
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};