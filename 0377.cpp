// First time
/*
    DP (Bottom-up)
    dp[i] denote how many combinations which sum is i
    (dp[0]=1 means there must be a empty combination which sum is 0)
    *Notice to use unsigned to avoid strangly overflow problem...
    T: O(nm)/S: O(m)
    -----
    Memoization + DP (Top-down)
    Calculate the dp[i] from target to 0
    T: O(nm)/S: O(m)
    -----
    Follow up:
    If there are negative problem in nums
    It will let the solution infinited
    ex. [-1, 1], target: 1 -> solutions: [1, -1, 1, -1 ... , 1, -1, 1]
    So we must need to add the constraint about negative number used times or the length of the solution
*/
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (int &num : nums) {
                if (i - num >= 0)
                    dp[i] += dp[i - num];
            }
        }
        return dp[target];
    }
};

// Or use another variable to calculate to avoid the strangly overflow
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; ++i) {
            long long ans = 0;
            for (int &num : nums) {
                if (i - num >= 0)
                    ans += dp[i - num];
            }
            dp[i] = (int)ans;
        }
        return dp[target];
    }
};

// Memoization
class Solution {
public:
    int helper(vector<int> &nums, int target, vector<int> &dp) {
        if (dp[target] != -1)
            return dp[target];
        int ans = 0;
        for (int &num : nums) {
            if (target - num >= 0)
                ans += helper(nums, target - num, dp);
        }
        return dp[target] = ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        dp[0] = 1;
        return helper(nums, target, dp);
    }
};