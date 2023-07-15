// First time
/*
    dp[0][i] means the max non-decreasing length ends on nums1[i]
    dp[1][i] means the max non-decreasing length ends on nums2[i]
    T: O(n)/S: O(n) -> can reduce to T: O(n)/S: O(1) like below
*/
class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int ans = 1, n = nums1.size();
        vector<vector<int>> dp(2, vector<int>(n, 1));
        for (int i=1; i<n; ++i) {
            if (nums1[i]>=nums1[i-1]) dp[0][i] = dp[0][i-1]+1;
            if (nums1[i]>=nums2[i-1]) dp[0][i] = max(dp[0][i], dp[1][i-1]+1);
            if (nums2[i]>=nums2[i-1]) dp[1][i] = dp[1][i-1]+1;
            if (nums2[i]>=nums1[i-1]) dp[1][i] = max(dp[1][i], dp[0][i-1]+1);
            ans = max(ans, max(dp[0][i], dp[1][i]));
        }
        return ans;
    }
};

/*
    [4, 16, 10, 8]
       \   /    -> [4, 4, 10, 8] or [4, 4, 10, 9]
    [8,  4,  1, 9]

    T: O(n)/S: O(1)
*/
class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int ans = 1, prev1 = 1, prev2 = 1, cur1 = 1, cur2 = 1;
        for (int i=1; i<nums1.size(); ++i) {
            /*
                If nums[i] is smaller then nums1[i-1] and nums2[i-1],
                the length will restart from 1
            */
            cur1 = 1, cur2 = 1;
            if (nums1[i]>=nums1[i-1]) cur1 = prev1+1;
            if (nums1[i]>=nums2[i-1]) cur1 = max(cur1, prev2+1);
            if (nums2[i]>=nums2[i-1]) cur2 = prev2+1;
            if (nums2[i]>=nums1[i-1]) cur2 = max(cur2, prev1+1);
            // ans = max({ans, cur1, cur2});
            ans = max(ans, max(cur1, cur2));
            prev1 = cur1;
            prev2 = cur2;
        }
        return ans;
    }
};