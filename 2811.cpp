// First time
/*
    Only need to check the nearby element sum>=m,
    because every sub-array which contain them, their sum will still >= m
    And it will be left ultimately then split to two single element sub-array
    T: O(n)/S: O(1)
*/
class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        if (nums.size()<3) return true;
        for (int i=0; i<nums.size()-1; ++i) {
            if (nums[i]+nums[i+1]>=m) return true;
        }
        return false;
    }
};

/*
    dp[l][r] denote the result for different start and end index of prefix sum of nums
    T: O(n^2)/S: O(n^2)
*/
class Solution {
public:
    bool help(vector<vector<int>> &dp, vector<int> &nums, int m, int l, int r) {
        if (r-l<3) return true; 
        bool ans=false;
        if (dp[l][r]!=-1) return dp[l][r];
        if (nums[r]-nums[l+1]>=m) ans|=help(dp, nums, m, l+1, r);
        if (nums[r-1]-nums[l]>=m) ans|=help(dp, nums, m, l, r-1);
        dp[l][r]=ans;
        return dp[l][r];
    }
    bool canSplitArray(vector<int>& nums, int m) {
        nums.insert(nums.begin(), 0);
        int n=nums.size(), l=0, r=n-1;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        partial_sum(nums.begin()+1, nums.end(), nums.begin()+1);
        return help(dp, nums, m, l, r);
    }
};