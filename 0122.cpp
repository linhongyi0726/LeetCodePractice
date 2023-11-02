// First time
/*
    The cost of new transaction is based on the profit of previous transaction
    -> Thus we can continually compute the total profit
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), profit = 0, buy = INT_MAX;
        for (int price : prices) {
            buy = min(buy, price - profit);
            profit = max(profit, price - buy);
        }
        return profit;
    }
};

/*
    Can do multiple transaction
    When the price start decreasing, we sell the holding stock and buy the new stock
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), ret = 0, buy = prices[0];
        for (int i = 1; i < n; ++i) {
            if (prices[i] < prices[i - 1]) {
                ret += prices[i - 1] - buy;
                buy = prices[i];
            }
        }
        // must sell at last day
        ret += prices[n - 1] - buy;
        return ret;
    }
};