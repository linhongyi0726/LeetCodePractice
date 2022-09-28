// First time
/*
    Fibonacci number problem
    1. dp[0]
        T: O(n)/S: O(n)
    2. Use variable to reduce dp space complexity
        T: O(n)/S: O(1)
*/
class Solution {
public:
    int climbStairs(int n) {
        int prev = 1;   //dp[0]
        int cur = 1;    //dp[1]
        for (int i = 2; i < n+1; ++i) {
            // dp[i] = dp[i-1] + dp[i-2]
            cur += prev;
            prev = cur - prev;
            /*
                int tmp = cur;
                cur += prev;
                prev = cur;
            */
        }
        return cur;     //dp[n]
    }
};