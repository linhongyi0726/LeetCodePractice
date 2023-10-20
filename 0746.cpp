// First time
/*
    Use two variables to record dp[i-1] and dp[i-2]
    to reduce the space complexity
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size(), prevprev = cost[0], prev = cost[1];
        for (int i = 2; i < n; ++i) {
            int tmp = prev;
            prev = cost[i] + min(prev, prevprev);
            prevprev = tmp;
        }
        return min(prevprev, prev);
    }
};

/*
    bottom up dp
    dp[i] denote the min cost to reach i floor
    T: O(n)/S: O(n)
*/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i) {
            if (i <= 1)
                dp[i] = cost[i];
            else
                dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        // just like return dp[n+1]
        return min(dp[n - 1], dp[n - 2]);
    }
};

/*
    top down dp with memoization
    dp[i] denote the min cost to reach i floor
    T: O(n)/S: O(n)
*/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);
        return min(dfs(cost, dp, n - 1), dfs(cost, dp, n - 2));
    }
    int dfs(vector<int> &cost, vector<int> &dp, int i) {
        if (i <= 1)
            return cost[i];
        if (dp[i] != -1)
            return dp[i];
        dp[i] = cost[i] + min(dfs(cost, dp, i - 1), dfs(cost, dp, i - 2));
        return dp[i];
    }
};

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // let the cost of top of floor = 0
        cost.push_back(0);
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        return dfs(cost, dp, n);
    }
    int dfs(vector<int> &cost, vector<int> &dp, int i) {
        if (i == 0)
            return 0;
        else if (i == 1)
            return cost[0];
        if (dp[i] != -1)
            return dp[i];
        dp[i] = cost[i - 1] + min(dfs(cost, dp, i - 1), dfs(cost, dp, i - 2));
        return dp[i];
    }
};