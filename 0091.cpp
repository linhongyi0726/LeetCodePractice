// First time
/*
    1D DP (reduce space complexity)
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int numDecodings(string s) {
        int n = s.length(), prepre = 1, pre = s[0] == '0' ? 0 : 1;
        for (int i = 2; i <= n; ++i) {
            int cur = 0;
            if (s[i - 1] != '0')
                cur += pre;
            if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))
                cur += prepre;
            prepre = pre;
            pre = cur;
        }
        return pre;
    }
};

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length(), prepre = 1, pre = s[0] == '0' ? 0 : 1;
        for (int i = 2; i <= n; ++i) {
            int cur = s[i - 1] != '0' ? pre : 0;
            // int num = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            int num = stoi(s.substr(i - 2, 2));
            if (num >= 10 && num <= 26)
                cur += prepre;
            prepre = pre;
            pre = cur;
        }
        return pre;
    }
};

/*
    1D DP
    T: O(n)/S: O(n)
*/
class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1;
        for (int i = 2; i <= n; ++i) {
            // 1 digits
            if (s[i - 1] != '0')
                dp[i] += dp[i - 1];
            // 2 digits
            if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))
                dp[i] += dp[i - 2];
        }
        return dp[n];
    }
};