// First time
/*
    Because we only check i and i-1 rows, we only need two rows
    Can reduce the space complexity
    T: O(nm)/S: O(n)
*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.length(), len2 = text2.length();
        vector<vector<int>> dp(2, vector(len2 + 1, 0));
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                if (text1[i - 1] == text2[j - 1])
                    dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + 1;
                else
                    dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[i % 2][j - 1]);
            }
        }
        return dp[len1 % 2][len2];
    }
};

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.length(), len2 = text2.length();
        vector<vector<int>> dp(2, vector(len2 + 1, 0));
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                if (text1[i - 1] == text2[j - 1])
                    dp[i & 1][j] = dp[(i - 1) & 1][j - 1] + 1;
                else
                    dp[i & 1][j] = max(dp[(i - 1) & 1][j], dp[i & 1][j - 1]);
            }
        }
        return dp[len1 & 1][len2];
    }
};

/*
    Compute LCS
    dp[i][j] denote the LCS of text1[0...i-1] and text2[0...j-1]
    ex.
    text1: sub1 + c1
    text2: sub2 + c2
    There are four cases:
    1. c1 is one of LCS but c2 not
        dp[i][j] = dp[i][j-1];
    2. c2 is one of LCS but c1 not
        dp[i][j] = dp[i-1][j];
    3. c1 and c2 both are LCS (c1==c2)
        dp[i][j] = dp[i-1][j-1]+1
    4. c1 and c2 both aren't LCS
        dp[i][j] = dp[i-1][j-1]
        -> In this case, we already check at dp[i][j-1] or dp[i-1][j]
        (means this status already moved to dp[i][j-1] and dp[i-1][j])

    T: O(nm)/S: O(nm)
*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.length(), len2 = text2.length();
        vector<vector<int>> dp(len1 + 1, vector(len2 + 1, 0));
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[len1][len2];
    }
};