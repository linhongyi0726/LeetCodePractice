// First time
/*
    DP
    Calculate each number appear times end at i-th length
    0: {4, 6}
    1: {6, 8}
    2: {7, 9}
    3: {4, 8}
    4: {0, 3, 9}
    5: {}
    6: {0, 1, 7}
    7: {2, 6}
    8: {1, 3}
    9: {2, 4}

    T: O(n*10)/S: O(n*10) -> can reduce to S: O(1)
*/
class Solution {
public:
    int knightDialer(int n) {
        // this also can be represented by an array in length 10
        unordered_map<int, vector<int>> mp = {{0, {4, 6}}, {1, {6, 8}}, {2, {7, 9}}, {3, {4, 8}}, {4, {0, 3, 9}}, {6, {0, 1, 7}}, {7, {2, 6}}, {8, {1, 3}}, {9, {2, 4}}};
        // also can only use two vectors to record pre and cur status
        vector<vector<int>> dp(n, vector<int>(10, 0));
        int ret = 0, mod = 1e9 + 7;
        for (int i = 0; i <= 9; ++i)
            dp[0][i] = 1;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j <= 9; ++j) {
                for (int num : mp[j]) {
                    dp[i + 1][num] = (dp[i + 1][num] + dp[i][j]) % mod;
                }
            }
        }
        for (int i = 0; i <= 9; ++i) {
            ret = (ret + dp[n - 1][i]) % mod;
        }
        return ret;
    }
};