// First time
/*
    The same with problem 1081
    Use one hash map/array to record the number of each character (or the last index of each character)
    -> it is used to check is there the same character at the behind
    Use another hash map/array to record the character in the stack(string), to skill the same character

    ex.
    [c, b, a, c, d]
        ^
    stack: [c] -> b < c and there still have 'c' at the behind -> pop 'c' and push 'b'

    T: O(n)/S: O(n)
*/
// Use array to record the last index
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> last(26, 0);
        vector<bool> used(26, false);
        string ret = "";
        int n = s.length();
        for (int i = 0; i < n; ++i)
            last[s[i] - 'a'] = i;
        for (int i = 0; i < n; ++i) {
            if (used[s[i] - 'a'])
                continue;
            while (!ret.empty() && ret.back() > s[i] && last[ret.back() - 'a'] > i) {
                used[ret.back() - 'a'] = false;
                ret.pop_back();
            }
            used[s[i] - 'a'] = true;
            ret += s[i];
        }
        return ret;
    }
};

// Use array
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> cnt(26, 0);
        vector<bool> used(26, false);
        string ret = "";
        int n = s.length();
        for (int i = 0; i < n; ++i)
            cnt[s[i] - 'a']++;
        for (char c : s) {
            cnt[c - 'a']--;
            if (used[c - 'a'])
                continue;
            while (!ret.empty() && ret.back() > c && cnt[ret.back() - 'a'] > 0) {
                used[ret.back() - 'a'] = false;
                ret.pop_back();
            }
            used[c - 'a'] = true;
            ret += c;
        }
        return ret;
    }
};

// Use hash map
class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> cnt;
        unordered_map<char, bool> seen;
        string ret = "";
        for (char c : s)
            cnt[c]++;
        for (char c : s) {
            if (!seen[c]) {
                while (!ret.empty() && ret.back() > c && cnt[ret.back()] > 0) {
                    seen[ret.back()] = false;
                    ret.pop_back();
                }
                seen[c] = true;
                ret += c;
            }
            cnt[c]--;
        }
        return ret;
    }
};