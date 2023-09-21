// First time
/*
    dp[i] denote the combinations of i orders
    Consider we have arranged n-1 orders already, then we want to insert the n th order
    The intervals that can be inserted are 2*(n-1)+1 = 2*n-1,
    And we can chose two positions or one position to insert (pickup/delivery divided or together)
    -> C(n, 2) + C(n, 1) = (2n-1)*(2n-2)/2 + (2n-1) = (2n-1)*(n)
    So dp[i] = dp[i-1] * (2*i-1)*i
    ----
    Math: (2n)!/2^n

    T: O(n)/ S: O(1)
*/
class Solution {
public:
    int countOrders(int n) {
        int mod = 1e9 + 7;
        long long ret = 1;
        for (int i = 2; i <= n; ++i)
            ret = ret * (2 * i - 1) * i % mod;
        return (int)ret;
    }
};

class Solution {
public:
    int countOrders(int n) {
        int mod = 1e9 + 7;
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i)
            dp[i] = dp[i - 1] * (2 * i - 1) * i % mod;
        return (int)dp[n];
    }
};

/*
    Recursion
    T: O(n)/ S: O(1)
*/
class Solution {
public:
    int countOrders(int n) {
        if (n == 1) return 1; 
        return (int)((long long)countOrders(n - 1) * (2 * n - 1) * n % (int)(1e9 + 7));
    }
};