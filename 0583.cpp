// First time
/*
    Treat it a LCS problem (problem 1143)
    dp[i][j] denote the LCS of word1[0...i-1] and word2[0...j-1],
    here can optimize the memory because we only care two rows (dp[i][j-1] and dp[i-1][j-1])
    and then return the non-LCS length

    T: O(nm)/S: O(n)
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();
        vector<vector<int>> dp(2, vector(len2 + 1, 0));
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i & 1][j] = dp[(i - 1) & 1][j - 1] + 1;
                else
                    dp[i & 1][j] = max(dp[(i - 1) & 1][j], dp[i & 1][j - 1]);
            }
        }
        return len1 + len2 - dp[len1 & 1][len2] * 2;
    }
};