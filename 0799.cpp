// First time
/*
    Like Pascal's triangle
       U     1
      U U    11
     U U U   121
    U U U U  1331

    2D DP
    Record all rows and glasses
    T: O(n^2)/S: O(n^2)
    -----
    1D DP
    Record rows one by one
    T: O(n^2)/S: O(n)
*/
// 1D DP
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> dp(101, 0);
        dp[0] = (double)poured;
        for (int i = 1; i <= query_row; ++i) {
            // Need to fill the champagne from bottom to front
            // to avoid to affect the glass we haven't see
            for (int j = i; j >= 0; --j) {
                dp[j] = max(0.0, (dp[j] - 1) / 2.0);
                dp[j + 1] += dp[j];
            }
        }
        return min(1.0, dp[query_glass]);
    }
};

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> cur(1, poured);
        for (int i = 0; i <= query_row; ++i) {
            vector<double> next(i + 2, 0);
            for (int j = 0; j < i + 1; ++j) {
                double excess = (cur[j] - 1) / 2.0;
                if (excess > 0) {
                    next[j] += excess;
                    next[j + 1] += excess;
                }
            }
            if (i != query_row)
                cur = next;
        }
        return min(1.0, cur[query_glass]);
    }
};

// 2D DP
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(101, vector<double>(101, 0.0));
        dp[0][0] = (double)poured;
        // We can only calculate to query_row-1 and query_glass, because it will fill to next row
        // for (int i = 0; i < query_row; ++i) {
        //     for (int j = 0; j <= query_glass; ++j) {
        for (int i = 0; i <= query_row; ++i) {
            for (int j = 0; j <= i + 1; ++j) {
                double excess = dp[i][j] - 1.00;
                if (excess > 0) {
                    dp[i + 1][j] += excess / 2.0;
                    dp[i + 1][j + 1] += excess / 2.0;
                }
            }
        }
        return min(1.0, dp[query_row][query_glass]);
    }
};