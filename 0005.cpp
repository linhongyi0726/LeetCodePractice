// Second time
/*
    2 ptr
    Choose middle point then 2 ptr to find the same character
    Notice to handle odd and even cases
    T: O(n^2)/S: O(1)
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length(), len = 1, start = 0;;
        for (int i = 0; i < n; ++i) {
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }
            if (r - l - 1 > len) {
                start = l + 1;
                len = r - l - 1;
            }
            l = i;
            r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }
            if (r - l - 1 > len) {
                start = l + 1;
                len = r - l - 1;
            }
        }
        return s.substr(start, len);
    }
};

/*
    DP
    dp[i][j] denote whether there is a palindrome start from i and end to j or not
    *Notice to add j-i=1 in the judgement to handle only 2 elements condition (avoid i+1 > j-1)

    T: O(n^2)/ S: O(n^2)
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length(), start = 0, len = 1;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i)
            dp[i][i] = true;
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j] && (j - i == 1 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    if (j - i + 1 > len) {
                        len = j - i + 1;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, len);
    }
};


// First time
/*
    Manacher's Algorithm
    dp[i] denote the radius of palindrome in center s[i]

                center       rbound
                   v           v
    X |X X X X X X X X X X X X X| X
           j               i
      the mirror of i

                center       rbound
                   v           v
    X |a b X b a X X X a b X b a| X
           j               i
   |______________|     according to dp[j], dp[i] can extend from 2
      dp[j] = 3

    *Notice the time complexity can be O(n)
    T: O(n)/S: O(n)
*/
class Solution {
public:
    string longestPalindrome(string s) {
        string t = "#";
        // To handle even length string
        for (auto c : s) {
            t += c ;
            t += "#";
        }
        int n = t.length();
        vector<int> dp(n, 0);
        int rbound = 0, center = 0, len = 0, start = 0;
        for (int i = 0; i < n; ++i) {
            int radius = 0;
            // If i is in right bound inside, can use mirror index j by center
            if (i < rbound) {
                int j = center - (i - center);
                radius = min(dp[j], rbound - i);
            }
            // extend to find palindrome
            while (i - radius >= 0 && i + radius < n && t[i - radius] == t[i + radius])
                radius++;
            dp[i] = radius - 1;
            // update right bound and center
            if (i + dp[i] > rbound) {
                rbound = i + dp[i];
                center = i;
            }
            // update LPS start and length
            if (dp[i] > len) {
                len = dp[i];
                start = i / 2 - len / 2;
            }
        }
        return s.substr(start, len);
    }
};

/*
    2 ptr
    choose a center and extend both side to find palindrome
    we also can skip the same characters to avoid even case
    -> the center in even case must have the same characters (ex. "aa")

    T: O(n^2)/S: O(1)
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length(), start = 0, len = 0;
        int l = 0, r = 0;
        for (int i = 0; i < n; ++i) {
            // skip the same characters
            r = i;
            while (r < n && s[i] == s[r])
                r++;
            // start to extend
            l = i - 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }
            if (r - l - 1 > len) {
                len = r - l - 1;
                start = l + 1;
            }
        }
        return s.substr(start, len);
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length(), start = 0, len = 0;
        for (int i = 0; i < n; ++i) {
            int l = i, r = i;
            // odd length case
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }
            if (r - l - 1 > len) {
                len = r - l - 1;
                start = l + 1;
            }
            // even length case
            l = i;
            r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }
            if (r - l - 1 > len) {
                len = r - l - 1;
                start = l + 1;
            }
        }
        return s.substr(start, len);
    }
};

/*
    DP
    dp[i][j] denote the s[i...j] is palindrome or not
    "a"   -> true
    "aa"  -> true
    "aba" -> check "b" is palindrome or not (dp[start+1][end-1])
    T: O(n^2)/S: O(n^2)
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length(), mxlen = 0, idx = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        // move from back
        for (int start = n - 1; start >= 0; --start) {
            for (int end = start; end < n; ++end) {
                if (s[start] != s[end])
                    continue;
                if (end - start <= 1 || dp[start + 1][end - 1]) {
                        dp[start][end] = true;
                    if (end - start + 1 > mxlen) {
                        mxlen = end - start + 1;
                        idx = start;
                    }
                }
            }
        }
        return s.substr(idx, mxlen);
    }
};

/*
    Reverse the string then it can be reduced to LCS problem
    s:     "babad"
    rev: "dabab"
           "bab" -> LCS of two string == LPS
    *Notice to check the LCS string are in corresponding index or check is reverse or not
    to avoid the fail case: "aacabdkacaa" -> "aaca" is LCS but not LPS

    T: O(n^2)/S: O(n^2)
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector(n + 1, 0));
        string rev = s, ret = "";
        reverse(rev.begin(), rev.end());
        int lps = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == rev[j - 1]) {
                    // record LCS
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    // check LPS
                    if (dp[i][j] > lps && i - dp[i][j] == n - j) {
                        lps = dp[i][j];
                        ret = s.substr(i - lps, lps);
                    }
                }
            }
        }
        return ret;
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<int>> dp(2, vector(n + 1, 0));
        string rev = s, ret = "";
        reverse(rev.begin(), rev.end());
        int lps = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == rev[j - 1]) {
                    // record LCS
                    dp[i & 1][j] = dp[(i - 1) & 1][j - 1] + 1;
                    // check LPS
                    if (dp[i & 1][j] > lps) {
                        string tmp = s.substr(i - dp[i & 1][j], dp[i & 1][j]);
                        string revtmp = tmp;
                        reverse(revtmp.begin(), revtmp.end());
                        if (tmp == revtmp) {
                            lps = dp[i & 1][j];
                            ret = tmp;
                        }
                    }
                } else {
                    // because here only use two rows to reduce memory,
                    // need to reset unused field
                    dp[i & 1][j] = 0;
                }
            }
        }
        return ret;
    }
};