// First time
/*
    Because backtracking TLE-> try DP
    1D-DP:
    dp[n] means "is there word break at n length of s?"
    *Notice to check dp[n] is already true or not, not let false result to cover it

    T: O(nm)/S: O(m)
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordset(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.length()+1, false);
        dp[0]=true;
        for (int i=0; i<=s.length(); ++i) {
            for (string word:wordset) {
                if (i<word.length()) continue;
                string sub=s.substr(i-word.length(), word.length());
                if (sub==word && !dp[i]) dp[i]=dp[i-word.length()];
                // if (sub==word) dp[i]=dp[i]|dp[i-word.length()];
                // if (wordset.count(sub) && !dp[i]) dp[i]=dp[i-word.length()];
            }
        }
        return dp[s.length()];
    }
};

/*
    Backtracking
    check every substr form specified idx then check remain string
    T: O(2^n)/S: O(n) -> TLE! (because of the constraints of s.length = 300)
*/
class Solution {
public:
    bool helper(string s, int idx, unordered_set<string>& wordset)
    {
        if (idx==s.length()) return true;
        for (int i=idx+1; i<=s.length(); ++i) {
            string sub = s.substr(idx, i-idx);
            if (wordset.count(sub) && helper(s, i, wordset)) return true;
        }
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordset(wordDict.begin(), wordDict.end());
        return helper(s,0,wordset);
    }
};