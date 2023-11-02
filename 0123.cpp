// First time
/*
    DP -> can be expanded to k-th transaction (problem 188)

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

    T: O(n*2)/S: O(n*2)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(3, vector<int>(n, 0));
        for (int times = 1; times <= 2; ++times) {
            int buy = prices[0];
            for (int day = 1; day < n; ++day) {
                buy = min(buy, prices[day] - dp[times - 1][day - 1]);
                dp[times][day] = max(dp[times][day - 1], prices[day] - buy);
            }
        }
        return dp[2][n - 1];
    }
};

/*
    Or change the order between the day and times, the concept is similar with problem 122,
    but we can do 2-th transaction in one day
    -> The same with below greedy approach

    T: O(n*2)/S: O(1)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> buy(3, INT_MAX);
        vector<int> profit(3, 0);
        for (int day = 0; day < n; ++day) {
            for (int times = 1; times <= 2; ++times) {
                buy[times] = min(buy[times], prices[day] - profit[times - 1]);
                profit[times] = max(profit[times], prices[day] - buy[times]);
            }
        }
        return profit[2];
    }
};

/*
    Choose minimum price to buy, and choose maximum profit to sell
    Notice the cost of second transaction is based on the profit of first transaction
    -> Thus we can continually compute the total profit
    T: O(n)/S: O(1)
*/
// Start from second day -> easy for understand
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = prices[0], profit1 = 0, buy2 = INT_MAX, profit2 = 0;
        for (int i = 1; i < prices.size(); ++i) {
            buy1 = min(buy1, prices[i]);
            profit1 = max(profit1, prices[i] - buy1);
            buy2 = min(buy2, prices[i] - profit1);
            profit2 = max(profit2, prices[i] - buy2);
        }
        return profit2;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = INT_MAX, profit1 = 0, buy2 = INT_MAX, profit2 = 0;
        for (int i = 0; i < prices.size(); ++i) {
            buy1 = min(buy1, prices[i]);
            profit1 = max(profit1, prices[i] - buy1);
            buy2 = min(buy2, prices[i] - profit1);
            profit2 = max(profit2, prices[i] - buy2);
        }
        return profit2;
    }
};