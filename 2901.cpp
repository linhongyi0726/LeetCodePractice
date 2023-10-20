// First time
/*
    Similar with the concept of longest increasing subsequence (LIS)

    dp[i] denote the length of longest subsequence in words[0:i]
    prev[i] denote the previous index of longest subsequence in [0:i]
    (means the dp[i] subsequence's index are [X, X, ..., prev[i], i])

    And use "lastidx" to record the last index of longest subsequence (equal to i),
    then we can use it to find the previous index of subsequence (prev[lastidx])
    until prev[lastidx] = -1, means no previous index (it's in begin)
    At last, reverse the ret array

     prev[prev[prev[lastidx]]]
        |  prev[prev[lastidx]]
        |        | prev[lastidx]
        |        |  |   lastidx
        v        v  v     v
    [X, X, X, X, X, X, X, i, X, X]
                    ^_____|
                 ^__|
        ^________|

    T: O(n^2)/S: O(n)
*/
class Solution {
public:
    bool chkstring(string s, string t) {
        if (s.length() != t.length())
            return false;
        int d = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != t[i])
                d++;
            if (d > 1)
                return false;
        }
        return true;
    }
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        vector<int> dp(n, 1), prev(n, -1);
        int mxlen = 0, lastidx = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (groups[i] != groups[j] && chkstring(words[i], words[j])) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                        // update the last index of longest subsequence
                        if (dp[i] > mxlen) {
                            mxlen = dp[i];
                            lastidx = i;
                        }
                    }
                }
            }
        }
        vector<string> ret;
        // append ret array from back to front
        while (lastidx != -1) {
            ret.push_back(words[lastidx]);
            lastidx = prev[lastidx];
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

/*
    dp[i] denote the longest subsequence in words[0:i]
    initialize dp[i] to words[i] means at least the subsequence must including ith word itself
    for every dp[i], iterate every words[0:i-1] to choose the longest subsequence
    Then return any subsequence which size is maximum

    T: O(n^2)/S: O(n^2)
*/
class Solution {
public:
    bool chkstring(string s, string t) {
        if (s.length() != t.length())
            return false;
        int d = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != t[i])
                d++;
            if (d > 1)
                return false;
        }
        return true;
    }
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        vector<vector<string>> dp(n);
        for (int i = 0; i < n; ++i)
            dp[i].push_back(words[i]);
        int mx = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (groups[i] != groups[j] && chkstring(words[i], words[j])) {
                    if (dp[j].size() + 1 > dp[i].size()) {
                        dp[i] = dp[j];
                        dp[i].push_back(words[i]);
                        mx = max(mx, int(dp[i].size()));
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (dp[i].size() == mx)
                return dp[i];
        }
        return {};
    }
};