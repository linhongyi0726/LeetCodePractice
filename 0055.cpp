// First time
/*
    Greedy
    choose the max between local max (i+nums[i]) and global max (m)
    T: O(n)/S: O(1)
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int m = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > m) return false;
            m = max(m, i+nums[i]);
            // if (m >= nums.size()) return true;
        }
        return true;
    }
};

/*
    DP
    T: O(n^2)/S: O(n)
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n, false);
        dp[0] = true;
        for (int i = 1; i < n; ++i) {
            for (int j = i-1; j >= 0; --j) {
                if (dp[j] && nums[j] >= i-j) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n-1];
    }
};