// First time
/*
    Permutations and constraints < 20 -> bitmask DP!!
    dp[idx][bitmask] = how many permutations that used by the same idx of number and mask
    p.s. basic permutation problem: Problem 46
    T: O(n * 2^n)/S: O(n * 2^n)
*/
class Solution {
public:
    int helper(vector<int>& nums, int mask, int prev, vector<vector<int>>& dp) {
        // mask fulled -> all number have been used
        if (mask==(1<<nums.size())-1) return 1;
        // -1 means not calculate yet
        if (dp[prev+1][mask]==-1) {
            int total=0;
            for (int i=0; i<nums.size(); ++i) {
                if (mask&(1<<i)) continue;
                if (prev==-1 || nums[prev]%nums[i]==0 || nums[i]%nums[prev]==0) {
                    total+=helper(nums, mask|(1<<i), i, dp);
                    total%=(int)(1e9+7);
                }
            }
            dp[prev+1][mask] = total;
        }
        return dp[prev+1][mask];
    }
    int specialPerm(vector<int>& nums) {
        // Notice the dp size: dp[nums.size+1][1<<(nums.size())] because we init dp in helper()
        vector<vector<int>> dp(nums.size()+1, vector<int>(1<<(nums.size()), -1));
        return helper(nums, 0, -1, dp);
    }
};

class Solution {
public:
    int helper(vector<int>& nums, int mask, int prev, vector<vector<int>>& dp) {
        // mask fulled -> all number have been used
        if (mask==(1<<nums.size())-1) return 1;
        // -1 means not calculate yet
        if (dp[prev][mask]==-1) {
            int total=0;
            for (int i=0; i<nums.size(); ++i) {
                if (mask&(1<<i)) continue;
                if (nums[prev]%nums[i]==0 || nums[i]%nums[prev]==0) {
                    total+=helper(nums, mask|(1<<i), i, dp);
                    total%=(int)(1e9+7);
                }
            }
            dp[prev][mask] = total;
        }
        return dp[prev][mask];
    }
    int specialPerm(vector<int>& nums) {
        // Notice the dp size: dp[nums.size][1<<(nums.size())]
        vector<vector<int>> dp(nums.size(), vector<int>(1<<(nums.size()), -1));
        // count the possibility for every number be first
        int ans=0;
        for (int i=0; i<nums.size(); ++i) {
            ans+=helper(nums, 1<<i, i, dp);
            ans%=(int)(1e9+7);
        }
        return ans;
    }
};