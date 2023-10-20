// First time
/*
    0/1 knapsack
    dp[i] denote the min cost to finish i walls
    Reduce the space complexity, reuse the dp array,
    but notice the second loop need to compute from back to front to avoid override the un-check elements
    (we only need left-top and top status)

    T: O(n^2)/S: O(n)
*/
class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<int> dp(n + 1, 1e9);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = n; j >= 0; --j) {
                dp[j] = min(dp[j], dp[max(0, j - time[i] - 1)] + cost[i]);
            }
        }
        return dp[n];
    }
};

// or use another array to record the status of previous loop
class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<int> dp(n + 1, 1e9);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            auto prev = dp;
            for (int j = 0; j <= n; ++j) {
                dp[j] = min(prev[j], prev[max(0, j - time[i] - 1)] + cost[i]);
            }
        }
        return dp[n];
    }
};

/*
    It can be treated to 0/1 knapsack problem

    dp[i][j] denote the minimum cost in considering i painter to finish j walls
    Because free painter only work when paid painter is working,
    we can treat the i'th paid painter can finish 1+time[i] walls, then only consider paid painters
    (1 paid painter finished and time[i] free painter finished)
    1. if we choose i'th painter:
        dp[i][j] = dp[i-1][j-(1+time[i-1])]
    2. if we not choose i;th painter:
        dp[i][j] = dp[i-1][j]

    p.s. init dp to 1e9 to avoid the over flow (or can init it to INT_MAX/2)
    T: O(n^2)/S: O(n^2)
*/
class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1e9));
        // no walls need to finish -> cost=0
        for (int i = 0; i <= n; ++i)
            dp[i][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                // dp[i][j] = min(dp[i - 1][j], dp[i - 1][max(0, j - time[i - 1] - 1)] + cost[i - 1]);
                int choose = dp[i - 1][max(0, j - time[i - 1] - 1)] + cost[i - 1];
                int nochoose = dp[i - 1][j];
                dp[i][j] = min(choose, nochoose);
            }
        }
        return dp[n][n];
    }
};