// First time
/*
    Use sliding window (two ptr)
    *Notice left pointer only move left, so use max function
    1. Hash map to store character already seen
        T: O(n)/S: O(n)
    2. Because s consists of English letters, digits, symbols and spaces,
    can use vector to reduce space complexity
        T: O(n)/S: O(1)
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int l = 0, ans = 0;
        for (int r = 0; r < s.length(); ++r) {
            if (mp.count(s[r]))
                l = max(l, mp[s[r]]+1);
            mp[s[r]] = r;
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> tbl(256, -1);
        int l = 0, ans = 0;
        for (int r = 0; r < s.length(); ++r) {
            if (tbl[s[r]]+1 > l)
                l = tbl[s[r]]+1;
            tbl[s[r]] = r;
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};