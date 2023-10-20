// First time
/*
    The same approach with problem 2901,
    but actually we can directly use greedy approach as below (T: O(n))

    Use LIS concept
    dp[i] denote the length of longest subsequence in words[0:i]
    prev[i] denote the previous index of longest subsequence in [0:i]
    (means the dp[i] subsequence's index are [X, X, ..., prev[i], i])

    T: O(n^2)/S: O(n)
*/
class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        vector<int> dp(n, 1), prev(n, -1);
        int mxlen = 0, lastidx = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (groups[i] != groups[j]) {
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
    Don't need to judge choosing group 0 or 1 first,
    just choose words[0], it will be the longest
    T: O(n)/S: O(1)
*/
class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        vector<string> ret;
        int prev = -1;
        for (int i = 0; i < n; ++i) {
            if (prev == -1 || groups[i] != groups[prev]) {
                prev = i;
                ret.push_back(words[i]);
            }
        }
        return ret;
    }
};

/*
    T: O(n)/S: O(1)
*/
class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        vector<string> ret0, ret1;
        int prev0 = -1, prev1 = -1;
        // choose the start (from group 0 or 1)
        for (int i = 0; i < n; ++i) {
            if (groups[i] == 0 && prev0 == -1) {
                prev0 = i;
                ret0.push_back(words[i]);
            } else if (groups[i] == 1 && prev1 == -1) {
                prev1 = i;
                ret1.push_back(words[i]);
            }
        }
        // the result which start from group 0
        if (prev0 != -1) {
            for (int i = prev0; i < n; ++i) {
                if (groups[i] != groups[prev0]) {
                    prev0 = i;
                    ret0.push_back(words[i]);
                }
            }   
        }
        // the result which start from group 1
        if (prev1 != -1) {
            for (int i = prev1; i < n; ++i) {
                if (groups[i] != groups[prev1]) {
                    prev1 = i;
                    ret1.push_back(words[i]);
                }
            }    
        }
        if (ret0.size() > ret1.size())
            return ret0;
        else
            return ret1;
    }
};