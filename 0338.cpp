// First time
/*
    i   binary  '1'
    0    0000    0
    -------------
    1    0001    1
    -------------
    2    0010    1 == dp[0] + 1
    3    0011    2 == dp[1] + 1
    -------------
    4    0100    1 == dp[0] + 1
    5    0101    2 == dp[1] + 1
    6    0110    2 == dp[2] + 1
    7    0111    3 == dp[3] + 1

    T: O(n)/S: O(n)
*/
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1, 0);
        int group = 1;
        for (int i = 1; i <= n; ++i) {
            if (!(i&(i-1))) group = i;
            dp[i] = dp[i-group] + 1;
        }
        return dp;
    }
};

/*
    i    binary '1'  i&(i-1)
    0    0000    0
    -----------------------
    1    0001    1    0000 (0) -> dp[0] + 1
    -----------------------
    2    0010    1    0000 (0) -> dp[0] + 1
    3    0011    2    0010 (2) -> dp[2] + 1
    -----------------------
    4    0100    1    0000 (0) -> dp[0] + 1
    5    0101    2    0100 (4) -> dp[4] + 1
    6    0110    2    0100 (4) -> dp[4] + 1
    7    0111    3    0110 (5) -> dp[5] + 1

    T: O(n)/S: O(n)
*/
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i&(i-1)] + 1;
        }
        return dp;
    }
};