// First time
/*
    DP (Bottom-up)
    dp[i] denote how many combinations which sum is i
    (dp[0]=1 means there must be a empty combination which sum is 0)

    "The test cases are generated so that the answer can fit in a 32-bit integer."
    *Notice to use unsigned to avoid overflow,
    (unsigned int overflow will be 0, but int overflow is undefined behavior)
    Or use another long long type variable to calculate then assign to dp[i],
    In this problem, long long type + int type will not overflow LLONG_MAX

    T: O(nm)/S: O(m)
    -----
    Memoization + DP (Top-down)
    Calculate the dp[i] from target to 0, this approach also can avoid overflow
    Because we only calculate used dp[i] instaed of creating whole dp vector.
    (There may are some unused dp[i] but overflow)
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

// use another long long variable to calculate to avoid overflow
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