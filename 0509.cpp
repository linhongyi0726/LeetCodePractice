// Second time
/*
    T: O(n)/S: O(n)
*/
class Solution {
public:
    int fib(int n) {
        if (n == 0)
            return 0;
        else if (n == 1)
            return 1;
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }
};


// First time
/*
    Golden Ratio formula
    T: O(1)/S: O(1)
*/
class Solution {
public:
    int fib(int n) {
        return round(pow((1 + sqrt(5)) / 2, n) / sqrt(5));
    }
};

/*
    DP -> bottom-up
    T: O(n)/S: O(n)
*/
class Solution {
public:
    int fib(int n) {
        if (n < 2) return n;
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

/*
    Recursion -> top-down
    T: O(2^n)/S: O(n)
*/
class Solution {
public:
    int fib(int n) {
        if (n < 2) return n;
        else return fib(n - 1) + fib(n - 2);
    }
};