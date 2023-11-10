// First time
/*
    Use formula (1+n)*n/2 or increase directly
    If using formula, notice to use long long to count to avoid overflow
    also need to count the last character after the loop

    T: O(n)/S: O(1)
*/
class Solution {
public:
    int countHomogenous(string s) {
        int n = s.length(), ret = 0, mod = 1e9 + 7;
        long long cnt = 1;
        for (int i = 1; i < n; ++i) {
            if (s[i] == s[i - 1]) {
                cnt++;
            } else {
                ret += ((1 + cnt) * cnt / 2) % mod;
                cnt = 1;
            }
        }
        ret += ((1 + cnt) * cnt / 2) % mod;
        return ret;
    }
};

class Solution {
public:
    int countHomogenous(string s) {
        int n = s.length(), cnt = 1, ret = 1, mod = 1e9 + 7;
        for (int i = 1; i < n; ++i) {
            if (s[i] == s[i - 1]) {
                cnt++;
            } else {
                cnt = 1;
            }
            ret = (ret + cnt) % mod;
        }
        return ret;
    }
};