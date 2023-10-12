// First time
/*
    1D DP
    Use two variables to record the left top(dp[i-1][j-1]) and top(dp[i-1][j]) elements

    T: O(n^2)/S: O(n)
*/
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() < nums2.size())
            swap(nums1, nums2);
        int n1 = nums1.size(), n2 = nums2.size(), lefttop = 0, top = 0;
        vector<int> dp(n2 + 1, 0);
        for (int i = 1; i <= n1; ++i) {
            lefttop = dp[0];
            for (int j = 1; j <= n2; ++j) {
                top = dp[j];
                if (nums1[i - 1] == nums2[j - 1])
                    dp[j] = lefttop + 1;
                else
                    dp[j] = max(dp[j - 1], top);
                lefttop = top;
            }
        }
        return dp[n2];
    }
};

/*
    2D DP (bottom-up)
    dp[i][j] denote the max uncrossed lines of nums1[0...i-1] and nums2[0...j-1]
    T: O(n^2)/S: O(n^2)
    -----
    2D DP (top-down)
    T: O(n^2)/S: O(n^2)
*/
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                if (nums1[i - 1] == nums2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        return dp[n1][n2];
    }
};

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        return dfs(nums1, nums2, dp, n1, n2);
    }
    int dfs(vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &dp, int i, int j) {
        if (i == 0 || j == 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (nums1[i - 1] != nums2[j - 1])
            dp[i][j] = max(dfs(nums1, nums2, dp, i, j - 1), dfs(nums1, nums2, dp, i - 1, j));
        else
            dp[i][j] = dfs(nums1, nums2, dp, i - 1, j - 1) + 1;
        return dp[i][j];
    }
};