// First time
/*
    DP
    dp[arr[i]] denote the number of binary trees when root is arr[i]
    Here we use hash map instead of vector to be dp data structure
    and use arr[i] instead of i to be the key of map
    Because we need to find the another child by root/child
    e.g.
    when arr[i] = arr[j] * arr[k]
    dp[arr[i]] = sum of (dp[arr[j]] * dp[arr[k]])
    -> arr[k] can be represented by arr[i]/arr[j], so we can reduce a for loop to find arr[k]

    Then ret is the sum of number of binary tree in every roots

    T: O(n^2)/S: O(n)
*/
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size(), ret = 0, mod = 1e9 + 7;
        unordered_map<int, long long> dp;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; ++i) {
            dp[arr[i]] = 1;
            for (int j = 0; j < i; ++j) {
                if (arr[i] % arr[j] == 0)
                    dp[arr[i]] = (dp[arr[i]] + dp[arr[j]] * dp[arr[i] / arr[j]]) % mod;
            }
            ret = (ret + dp[arr[i]]) % mod;
        }
        return ret;
    }
};

/*
    TLE!
    DP
    dp[i] denote the number of binary trees when root is arr[i]
    T: O(n^3)/S: O(n)
*/
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size(), ret = 0, mod = 1e9 + 7;
        vector<long long> dp(n, 1);
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                for (int k = 0; k < i; ++k) {
                    if ((long long)arr[j] * arr[k] == arr[i])
                        dp[i] = (dp[i] + dp[j] * dp[k]) % mod;
                }
            }
            ret = (ret + dp[i]) % mod;
        }
        return ret;
    }
};