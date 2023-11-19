// Fourth time
/*
    Use hash set to record the character in the window
    T: O(n)/S: O(n)
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), l = 0, r = 0, ret = 0;
        unordered_set<char> st;
        for (; r < n; ++r) {
            while (st.count(s[r]))
                st.erase(s[l++]);
            st.insert(s[r]);
            ret = max(ret, (int)st.size());
        }
        return ret;
    }
};

/*
    Use hash map to record the last index of character we had visited
    T: O(n)/S: O(n)
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), l = 0, r = 0, ret = 0;
        unordered_map<char, int> mp;
        for (; r < n; ++r) {
            if (mp.count(s[r]))
                l = max(l, mp[s[r]] + 1);
            mp[s[r]] = r;
            ret = max(ret, r - l + 1);
        }
        return ret;
    }
};


// Third time
/*
    Sliding window + hash map/hash set
    T: O(n)/S: O(n)
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int ans = 0, l = 0, r = 0;
        for (; r<s.length(); ++r) {
            if (mp.count(s[r]) && mp[s[r]]+1 > l) l=mp[s[r]]+1;
            mp[s[r]]=r;
            ans=max(ans, r-l+1);
        }
        return ans;
    }
};


// Second time
/*
    Sliding window + hash set
    *Note: If we barely move l=r+1, it will fail in case "dvdf"
    -> need to move l to 1nd "d"'s index +1 when we visit 2nd "d"
    T: O(n)/S: O(n)
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int ans = 0, l = 0;
        for (int r = 0; r < s.length(); ++r) {
            while (set.count(s[r])) {
                set.erase(s[l]);
                l++;
            }
            set.insert(s[r]);
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int ans = 0, l = 0, r = 0;
        while (r < s.length()) {
            if (set.count(s[r])) {
                set.erase(s[l]);
                l++;
            } else {
                set.insert(s[r]);
                ans = max(ans, r-l+1);
                r++;
            }
        }
        return ans;
    }
};

/*
    Sliding window + hash map
    T: O(n)/S: O(n)
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int ans = 0, l = 0;
        for (int r = 0; r < s.length(); ++r) {
            if (mp.count(s[r])) {
                // In case "abba", need to avoid l going back to index 0+1 when we visit 2nd "a"
                l = max(l, mp[s[r]]+1);
            }
            mp[s[r]] = r;
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};


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