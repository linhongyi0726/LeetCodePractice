// First time
/*
    1D DP
    dp[i] denotes the maximum amount of money in i houses
    dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]) to choose robbing this house or not
    T: O(n)/S: O(n)
    -----
    Reduce to 0D DP (constant space)
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        dp[1] = nums[0];
        for (int i = 2; i <= n; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }
        return dp[n];
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), prev1 = 0, prev2 = 0;
        for (int i = 0; i < n; ++i) {
            int cur = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = cur;
        }
        return max(prev1, prev2);
    }
};