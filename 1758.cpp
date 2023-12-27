// First time
/*
    Compare the operations of two possible patterns

    T: O(n)/S: O(1)
*/
class Solution {
public:
    int minOperations(string s) {
        int ret0 = 0, n = s.length();
        // 010101
        for (int i = 0; i < n; ++i) {
            if (s[i] - '0' != i % 2)
                ret0++;
        }
        return min(ret0, n - ret0);
    }
};

class Solution {
public:
    int minOperations(string s) {
        int ret0 = 0;
        char cur = '0';
        for (char c : s) {
            if (c != cur)
                ret0++;
            if (cur == '0')
                cur = '1';
            else
                cur = '0';
        }
        return min(ret0, (int)s.length() - ret0);
    }
};

class Solution {
public:
    int minOperations(string s) {
        int ret0 = 0, ret1 = 0;
        char cur = '0';
        for (char c : s) {
            if (c != cur)
                ret0++;
            if (cur == '0')
                cur = '1';
            else
                cur = '0';
        }
        cur = '1';
        for (char c : s) {
            if (c != cur)
                ret1++;
            if (cur == '0')
                cur = '1';
            else
                cur = '0';
        }
        return min(ret0, ret1);
    }
};