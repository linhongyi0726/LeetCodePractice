// First time
/*
    Follow-up
    If there are too mant string s to check, we can record all character of string t with their indx
    Then binary search to check the index is increasing

    ex. s="abc", t="bahbgdca"
    idx=[a={1,7}, b={0,3}, c={6}]
    i=0 ('a'): prev=1
    i=1 ('b'): prev=3
    i=2 ('c'): prev=6 (return true)

    T: O(mlogn)/S: O(n)
*/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        unordered_map<char, vector<int>> mp;
        int lens = s.length(), lent = t.length();
        for (int i = 0; i < lent; ++i)
            mp[t[i]].push_back(i);
        int prev = -1;
        for (int i = 0; i < lens; ++i) {
            int idx = upper_bound(mp[s[i]].begin(), mp[s[i]].end(), prev) - mp[s[i]].begin();
            if (idx != mp[s[i]].size())
                prev = mp[s[i]][idx];
            else
                return false;
        }
        return true;
    }
};

/*
    2D DP
    dp[i][j] denote the length of subsequence s[0...i-1] in t[0...j-1]
    T: O(nm)/S: O(nm)
*/
// Top-down
class Solution {
public:
    int helper(string s, string t, vector<vector<int>> &dp, int lens, int lent) {
        if (lens == 0 || lent == 0)
            return 0;
        if (dp[lens][lent] != -1)
            return dp[lens][lent];
        if (s[lens - 1] == t[lent - 1])
            dp[lens][lent] = 1 + helper(s, t, dp, lens - 1, lent - 1);
        else
            dp[lens][lent] = helper(s, t, dp, lens, lent - 1);
        return dp[lens][lent];
    }
    bool isSubsequence(string s, string t) {
        int lens = s.length(), lent = t.length();
        vector<vector<int>> dp(lens + 1, vector<int>(lent + 1, -1));
        return helper(s, t, dp, lens, lent) == lens;
    }
};

// Bottom-up
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int lens = s.length(), lent = t.length();
        vector<vector<int>> dp(lens + 1, vector<int>(lent + 1, 0));
        for (int i = 1; i <= lens; ++i) {
            for (int j = 1; j <= lent; ++j) {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = dp[i][j - 1];
                if (dp[i][j] == lens)
                    return true;
            }
        }
        return dp[lens][lent] == lens;
    }
};

/*
    2D DP
    dp[i][j] denote the s[0...i-1] is subsequence of t[0...j-1]

    ex. s = "axc", t = "ahbgdc"
       "" a h b g d c
    "" T  T T T T T T
    a  F  T T T T T T
    x  F  F F F F F F
    c  F  F F F F F _ -> it's false because dp[3-1][6-1] is false, means "x" not in the string t

    T: O(nm)/S: O(nm)
*/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int lens = s.length(), lent = t.length();
        vector<vector<bool>> dp(lens + 1, vector<bool>(lent + 1, false));
        for (auto b : dp[0])
            b = true;
        for (int i = 1; i <= lens; ++i) {
            for (int j = 1; j <= lent; ++j) {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }
        return dp[lens][lent];
    }
};

/*
    Recursion
    2 ptr
    T: O(n)/S: O(n) or O(1) because of tail recursion that compiler can optimize it
*/
class Solution {
public:
    bool helper(string &s, string &t, int sidx, int tidx) {
        if (sidx == s.length())
            return true;
        if (tidx == t.length())
            return false;
        if (s[sidx] == t[tidx])
            return helper(s, t, sidx + 1, tidx + 1);
        else
            return helper(s, t, sidx, tidx + 1);
    }
    bool isSubsequence(string s, string t) {
        return helper(s, t, 0, 0);
    }
};

/*
    Iteration
    2 ptr
    T: O(n)/S: O(1)
*/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0;
        for (int i = 0; i < t.length() && j < s.length(); ++i) {
            if (s[j] == t[i])
                j++;
        }
        return j == s.length();
    }
};

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s == t)
            return true;
        int idx = 0;
        for (int i = 0; i < t.length(); ++i) {
            if (s[idx] == t[i])
                idx++;
            if (idx == s.length())
                return true;
        }
        return false;
    }
};