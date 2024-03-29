// Second time
/*
    Use sliding windows to find the number of character >= k
    And limit the unique characters in the window, (over the limit -> shrink the window)
    When all unique characters's number is greater or equal to k
    -> compute the length

    T: O(n*26)/S: O(26)
*/
class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length(), ret = 0;
        for (int num = 1; num <= 26; ++num) {
            vector<int> cnt(26, 0);
            int l = 0, r = 0, uni = 0, numk = 0;
            for (; r < n; ++r) {
                if (cnt[s[r] - 'a'] == 0)
                    uni++;
                if (++cnt[s[r] - 'a'] == k)
                    numk++;
                while (l < r && uni > num) {
                    if (cnt[s[l] - 'a'] == k)
                        numk--;
                    cnt[s[l] - 'a']--;
                    if (cnt[s[l++] - 'a'] == 0)
                        uni--;
                }
                if (uni == numk)
                    ret = max(ret, r - l + 1);
            }
        }
        return ret;
    }
};

/*
    Divide and conquer
    T: O(n^2)/S: O(n)
*/
class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        unordered_map<char, int> mp;
        for (int i = 0; i < n; ++i)
            mp[s[i]]++;
        int idx = 0;
        for (; idx < n; ++idx) {
            if (mp[s[idx]] < k)
                break;
        }
        if (idx == n)
            return idx;
        int l = longestSubstring(s.substr(0, idx), k);
        int r = longestSubstring(s.substr(idx + 1), k);
        return max(l, r);
    }
};


// First time
/*
    2 ptr
    Add one more restriction by ourself: numbers of unique character in the window
    -> it will be 26 at most
    It's better to know when to shrink the window
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int longestSubstring(string s, int k) {
        int ans = 0, n = s.length();
        for (int i = 1; i <= 26; ++i) {
            vector<int> cnt(26, 0);
            int l = 0, r = 0, unique = 0, numk = 0;
            while (r < n) {
                if (cnt[s[r] - 'a']++ == 0) unique++;
                if (cnt[s[r++] - 'a'] == k) numk++;
                while (unique > i) {
                    if (cnt[s[l] - 'a']-- == k) numk--;
                    if (cnt[s[l++] - 'a'] == 0) unique--;
                }
                if (unique == numk) ans = max(ans, r - l);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int longestSubstring(string s, int k) {
        int ans = 0, n = s.length();
        for (int i = 1; i <= 26; ++i) {
            vector<int> cnt(26, 0);
            int l = 0, r = 0, unique = 0, numk = 0;
            while (r < n) {
                if (unique <= i) {
                    // not satisfied: increase window
                    if (cnt[s[r] - 'a'] == 0) unique++;
                    cnt[s[r] - 'a']++;
                    if (cnt[s[r] - 'a'] == k) numk++;
                    r++;
                } else {
                    // satisfied: decrease window
                    if (cnt[s[l] - 'a'] == k) numk--;
                    cnt[s[l] - 'a']--;
                    if (cnt[s[l] - 'a'] == 0) unique--;
                    l++;
                }
                if (unique == numk) ans = max(ans, r - l);
            }
        }
        return ans;
    }
};

/*
    Divide & conquer
    T: O(n^2)/S: O(n)
*/
class Solution {
public:
    int longestSubstring(string s, int k) {
        unordered_map<char, int> cnt;
        for (char c : s ) cnt[c]++;
        int idx = 0, n = s.length();
        for (; idx < n; ++idx) {
            if (cnt[s[idx]] < k) break;
        }
        if (idx == n) return idx;
        int l = longestSubstring(s.substr(0, idx), k);
        // int r = longestSubstring(s.substr(idx + 1), k);
        int r = longestSubstring(s.substr(idx + 1, n - 1 - idx), k);
        return max(l, r);
    }
};

// optimize -> before find right side, find the next valid idx first
class Solution {
public:
    int longestSubstring(string s, int k) {
        unordered_map<char, int> cnt;
        for (char c : s ) cnt[c]++;
        int idx = 0, n = s.length();
        while (idx < n && cnt[s[idx]] >= k) idx++;
        if (idx == n) return n;
        int l = longestSubstring(s.substr(0, idx), k);
        while (idx < n && cnt[s[idx]] < k) idx++;
        // int r = longestSubstring(s.substr(idx), k);
        int r = longestSubstring(s.substr(idx, n - idx), k);
        return max(l, r);
    }
};