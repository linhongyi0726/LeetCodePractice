// First time
/*
    Optimize the space complexity
    Use three variables to replace the status of dp[i-1], dp[i-2], dp[i-3]
    T: O(n)/S: O(1)
*/
class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        int n = nums.size();
        long long pre1 = 0, pre2 = 0, pre3 = 0;
        for (int i = 0; i < n; ++i) {
            long long cur = max(0, k - nums[i]) + min({pre1, pre2, pre3});
            pre3 = pre2;
            pre2 = pre1;
            pre1 = cur;
        }
        return min({pre1, pre2, pre3});
    }
};

/*
    Similar with problem 198 House Robber
    Tabulation DP
    dp[i] demote the minimum operation to let nums[0...i] satisfy (and nums[i] will >= k)
    At last, choose the minimum of last three elements in the dp array
    (Because whatever which one be >= k will be correct)

    T: O(n)/S: O(n)
*/
class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> dp(n, 0);
        dp[0] = max(0, k - nums[0]);
        dp[1] = max(0, k - nums[1]);
        dp[2] = max(0, k - nums[2]);
        for (int i = 3; i < n; ++i) {
            dp[i] = max(0, k - nums[i]) + min({dp[i - 1], dp[i - 2], dp[i - 3]});
        }
        return min({dp[n - 3], dp[n - 2], dp[n - 1]});
    }
};

/*
    Memoization DP
    T: O(n)/S: O(n)
*/
class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> dp(n, -1);
        return dfs(nums, k, dp, 0);
    }
    long long dfs(vector<int> &nums, int k, vector<long long> &dp, int i) {
        if (i > nums.size() - 3)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        long long case1 = max(0, k - nums[i]) + dfs(nums, k, dp, i + 1);
        long long case2 = max(0, k - nums[i + 1]) + dfs(nums, k, dp, i + 2);
        long long case3 = max(0, k - nums[i + 2]) + dfs(nums, k, dp, i + 3);
        dp[i] = min({case1, case2, case3});
        return dp[i];
    }
};