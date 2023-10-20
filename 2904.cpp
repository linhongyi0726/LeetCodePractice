// First time
/*
    Sliding window
    Notice to judge the length of possible answer,
    if it's the same with previous candidate, choose lexicographically smaller one
    T: O(n)/S: O(n)
*/
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int l = 0, r = 0;
        int n = s.length(), cnt = 0, len = n;
        string ret = s;
        for (; r < n; ++r) {
            if (s[r] == '1')
                cnt++;
            while (l < n && (s[l] != '1' || cnt > k)) {
                if (s[l++] == '1')
                    cnt--;
            }
            if (cnt == k && r - l + 1 <= len) {
                string tmp = s.substr(l, r - l + 1);
                if (tmp.length() != ret.length()) { // tmp.length() < ret.length()
                    ret = tmp;
                    len = ret.length();
                } else if (tmp < ret) {     // tmp.length() == ret.length() && tmp is lexicographically smaller
                    ret = tmp;
                    len = ret.length();
                }
            }
        }
        return cnt == k ? ret : "";
    }
};

/*
    neat code
    initialize ret to "", so we don't need to judge before return
    But notice to modify len initialization to n+1,
    it will let us update ret when we first find possible answer
    T: O(n)/S: O(n)
*/
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length(), cnt = 0, len = n + 1;
        string ret = "";
        for (int l = 0, r = 0; r < n; ++r) {
            if (s[r] == '1')
                cnt++;
            while (s[l] == '0' || cnt > k) {
                if (s[l++] == '1')
                    cnt--;
            }
            if (cnt == k && r - l + 1 <= len) {
                string tmp = s.substr(l, r - l + 1);
                if (tmp.length() < len || (tmp.length() == len && tmp < ret)) {
                    ret = tmp;
                    len = r - l + 1;
                }
            }
        }
        return ret;
    }
};