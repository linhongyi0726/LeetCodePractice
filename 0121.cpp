// Third time
/*
    Kadane's Algorithm
    Calculate every day's profit if we sell stock at that day
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cur = 0, ret = 0;
        for (int i = 1; i < prices.size(); ++i) {
            cur = max(0, cur + prices[i] - prices[i - 1]);
            ret = max(ret, cur);
        }
        return ret;
    }
};

/*
    Choose the day which has lowest price to buy
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0, buy = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            ret = max(ret, prices[i] - buy);
            buy = min(buy, prices[i]);
        }
        return ret;
    }
};


// Second time
/*
    Only one transaction
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, buy = prices[0];
        for (int price : prices) {
            profit = max(profit, price - buy);
            buy = min(buy, price);
        }
        return profit;
    }
};


// First time
/*
    Dynamic Programming?
    Traverse all the prices and save the minimum
    Then return the max of profit
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int local_min = prices[0];
        for (int p : prices) {
            local_min = p < local_min ? p : local_min;
            ans = ans > (p - local_min) ? ans : (p - local_min);
        }
        return ans;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int local_min = prices[0];
        for (int p : prices) {
            local_min = min(p, local_min);
            ans = max(ans, (p-local_min));
        }
        return ans;
    }
};