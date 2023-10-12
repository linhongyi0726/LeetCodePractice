// First time
/*
    prefix sum + 3D DP
    Use prefix sum to handle the for loop in case 2 (append integer == mx)
    Also no need to accumulate the state which mx <= m, just return the prefix sum result

    T: O(n*m*k)/S: O(n*m*k)
*/
class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        const int mod = 1e9 + 7;
        vector<vector<vector<long long>>> dp(n + 1,vector<vector<long long>>(m + 1, vector<long long>(k + 1, 0)));
        vector<vector<vector<long long>>> prefix(n + 1,vector<vector<long long>>(m + 1, vector<long long>(k + 1, 0)));
        for (int mx = 0; mx <= m; ++mx) {
            dp[1][mx][1] = 1;
            prefix[1][mx][1] = mx;
        }
        for (int len = 1; len <= n; ++len) {
            for (int mx = 1; mx <= m; ++mx) {
                for (int cost = 1; cost <= k; ++cost) {
                    // case 1: append integer which <= mx
                    dp[len][mx][cost] = (dp[len][mx][cost] + mx * dp[len - 1][mx][cost]) % mod;
                    // case 2: append integer which == mx
                    // transfer the sum of dp[len-1][i][cost-1] to prefix[len-1][mx-1][cost-1]
                    dp[len][mx][cost] = (dp[len][mx][cost] + prefix[len - 1][mx - 1][cost - 1]) % mod;
                    prefix[len][mx][cost] = (prefix[len][mx - 1][cost] + dp[len][mx][cost]) % mod;
                }
            }
        }
        return prefix[n][m][k];
    }
};

/*
    3D DP (bottom-up)

    dp[len][mx][cost] denote the amount of arrays when array size is len and max is mx and search cost is cost

    Consider two cases:
    1. append integer <= mx:
        We can append 1...mx in dp[len-1][mx][cost] (don't need to change max and cost)
        transfer the state which max = mx
        -> dp[len][mx][cost] = mx * dp[len-1][mx][cost]
    2. append integer == mx:
        We can append mx in every dp[len-1][x][cost-1] where x = 1...mx-1
        transfer the state which max < mx
        -> dp[len][mx][cost] = sum of dp[len-1][1...mx-1][cost-1]
    Then accumulate every dp states which mx <= m

    T: O(n*m^2*k)/S: O(n*m*k)
*/
class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        const int mod = 1e9 + 7;
        vector<vector<vector<long long>>> dp(n + 1,vector<vector<long long>>(m + 1, vector<long long>(k + 1, 0)));
        for (int mx = 1; mx <= m; ++mx)
            dp[1][mx][1] = 1;
        for (int len = 1; len <= n; ++len) {
            for (int mx = 1; mx <= m; ++mx) {
                for (int cost = 1; cost <= k; ++cost) {
                    // not need to use search cost -> append integer which <= mx
                    dp[len][mx][cost] = (dp[len][mx][cost] + mx * dp[len - 1][mx][cost]) % mod;
                    // need to use one search cost -> append integer which == mx
                    for (int i = 1; i < mx; ++i)
                        dp[len][mx][cost] = (dp[len][mx][cost] + dp[len - 1][i][cost - 1]) % mod;
                }
            }
        }
        long long ret = 0;
        for (int mx = 1; mx <= m; ++mx)
            ret = (ret + dp[n][mx][k]) % mod;
        return ret;
    }
};