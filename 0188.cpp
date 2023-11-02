// First time
/*
    DP (similar with problem 123)
    dp[i][j] denote the max profit after do i-th transaction at j day
    at every j day, we have two options:
    1. hold:
        the profit is the same with previous day
        -> dp[i][j] = dp[i][j-1]
    2. sell:
        the profit is the profit at the day we buy stock plus the profit this time
        -> dp[i][j] = dp[i-1][m] + price[j] - price[m]
           m means the day we buy this stock
    Then the problem is how to compute the profit (or the price we buy)
    We can use the same trick in greedy approach to record the minimum buying price

    T: O(nk)/S: O(nk)
*/
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(k + 1, vector<int>(n, 0));
        for (int times = 1; times <= k; ++times) {
            int buy = prices[0];
            for (int day = 1; day < n; ++day) {
                buy = min(buy, prices[day] - dp[times - 1][day - 1]);
                dp[times][day] = max(dp[times][day - 1], prices[day] - buy);
            }
        }
        return dp[k][n - 1];
    }
};

/*
    Or change the order between the day and times, the concept is similar with problem 122,
    but we can do k-th transaction in one day
    -> The same with below greedy approach

    T: O(nk)/S: O(k)
*/
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> buy(k + 1, INT_MAX);
        vector<int> profit(k + 1, 0);
        for (int day = 0; day < n; ++day) {
            for (int times = 1; times <= k; ++times) {
                buy[times] = min(buy[times], prices[day] - profit[times - 1]);
                profit[times] = max(profit[times], prices[day] - buy[times]);
            }
        }
        return profit[k];
    }
};

/*
    Another thinking direction
    Traverse all days to compute the profit at i-th transaction 

    T: O(nk)/S: O(n)
*/
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> buy(n, INT_MAX);
        vector<int> profit(n, 0);
        buy[0] = prices[0];
        for (int times = 1; times <= k; ++times) {
            for (int day = 1; day < n; ++day) {
                buy[day] = min(buy[day - 1], prices[day] - profit[day]);
                profit[day] = max(profit[day - 1], prices[day] - buy[day - 1]);
            }
        }
        return profit[n - 1];
    }
};