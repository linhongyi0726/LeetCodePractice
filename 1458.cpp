// First time
/*
    1D DP
    Use two variables to record the upper left(dp[i-1][j-1]) and upper(dp[i-1][j]) elements

    T: O(n^2)/S: O(n)
*/
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size(), upperleft = 0, upper = 0;
        vector<int> dp(n2 + 1, INT_MIN);
        for (int i = 1; i <= n1; ++i) {
            upperleft = dp[0];
            for (int j = 1; j <= n2; ++j) {
                upper = dp[j];
                dp[j] = max({nums1[i - 1] * nums2[j - 1] + max(upperleft, 0), upper, dp[j - 1]});
                upperleft = upper;
            }
        }
        return dp[n2];
    }
};

/*
    Similar with LCS problem (1035, 1143)

    *dot product:
        a = [a1, a2], b = [b1, b2]
        a．b = a1*b1 + a2*b2

    2D DP (bottom-up)
    dp[i][j] denote the max product of nums1[0...i-1] and nums2[0...j-1]

        j-1 j
    i-1  A  B
    i    C  D
    There are four cases when we compute dp[i][j]
    A: ignore i and j, just carry from dp[i-1][j-1] -> It will be computed and transferred to dp[i-1][j] and dp[i][j-1]
        dp[i-1][j] = max(dp[i-2][j-1] + (i-1)*j, dp[i-2][j], dp[i-1][j-1])
        dp[i][j-1] = max(dp[i-1][j-2] + i*(j-1), dp[i-1][j-1], dp[i][j-2])
    B: ignore i, just carry from dp[i-1][j]
    C: ignore j, just carry from dp[i][j-1]
    D: choose both i and j, dp[i-1][j-1] + i*j
    So we only need to consider B, C, D cases

    T: O(nm)/S: O(nm)
    -----
    2D DP (top-down)
    T: O(nm)/S: O(nm)
*/
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, INT_MIN));
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                // choose both or not, max(dp[i-1][j-1], 0) to ensure we use positive p[i-1][j-1]
                dp[i][j] = nums1[i - 1] * nums2[j - 1] + max(dp[i - 1][j - 1], 0);
                // choose one of it
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                // dp[i][j] = max(nums1[i - 1] * nums2[j - 1] + max(dp[i - 1][j - 1], 0), max(dp[i - 1][j], dp[i][j - 1]));
            }
        }
        return dp[n1][n2];
    }
};

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, INT_MIN));
        return dfs(nums1, nums2, dp, n1, n2);
    }
    int dfs(vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &dp, int i, int j) {
        if (i == 0 || j == 0)
            return INT_MIN;
        if (dp[i][j] != INT_MIN)
            return dp[i][j];
        dp[i][j] = nums1[i - 1] * nums2[j - 1] + max(dfs(nums1, nums2, dp, i - 1, j - 1), 0);
        dp[i][j] = max(dp[i][j], dfs(nums1, nums2, dp, i - 1, j));
        dp[i][j] = max(dp[i][j], dfs(nums1, nums2, dp, i, j - 1));
        return dp[i][j];
    }
};