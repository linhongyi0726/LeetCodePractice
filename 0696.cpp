// Second time
/*
    choose the smaller between the size of prev and cur group
    Notice to start with cur=1 because we start at i=1
    and after comparing prev and cur, also need to initialize cur=1
    (to start counting the next new pair of group prev and cur)

    "0 0 1 1 0 0 1 1"
    |___|___|
    prev cur

    T: O(n)/S: O(1)
*/
class Solution {
public:
    int countBinarySubstrings(string s) {
        int ret = 0, prev = 0, cur = 1;
        for (int i = 1; i <= s.length(); ++i) {
            if (s[i] != s[i - 1] || i == s.length()) {
                ret += min(prev, cur);
                prev = cur;
                cur = 1;
            } else {
                cur++;
            }
        }
        return ret;
    }
};


// First time
/*
    Group '0' and '1', then choose minium of continuous number

    Ex.
    00011111
    0: continuous 3 times
    1: continuous 5 times
    min(3,5) = 3 -> 000111, 0011, 01

    T: O(n)/S: O(1)
*/
class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0, pre = 0, cur = 1;
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == s[i-1]) cur++;
            else {
                ans += min(pre, cur);
                pre = cur;
                cur = 1;
            }
        }
        ans += min(pre, cur);   //last group
        return ans;
    }
};

class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0, pre = 0, cur = 1;
        for (int i = 0; i < s.length(); ++i) {
            if (i+1 < s.length() && s[i] == s[i+1]) cur++;
            else {
                ans += min(pre, cur);
                pre = cur;
                cur = 1;
            }
        }
        return ans;
    }
};

/*
    Use two ptr to count continuous number
*/
class Solution {
public:
    int countBinarySubstrings(string s) {
        int l = 0, r = 0, ans = 0, pre = 0;
        while (l < s.length()) {
            r = l;
            while (r+1 < s.length() && s[r] == s[r+1]) ++r;
            ans += min(pre, r-l+1);
            pre = r-l+1;
            l = r+1;
        }
        return ans;
    }
};