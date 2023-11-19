// First time
/*
    length 3 palindromes -> xyx
    Just need to find the first index and the last index of each character,
    then compute the unique character between this two index

    T: O(n)/S: O(n)
*/
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char, pair<int, int>> idx;
        int n = s.length(), ret = 0;
        for (int i = 0; i < n; ++i) {
            if (!idx.count(s[i]))
                idx[s[i]] = {i, i};
            else
                idx[s[i]].second = i;
        }
        for (auto [c, p] : idx) {
            unordered_set<char> st;
            for (int i = p.first + 1; i < p.second; ++i) {
                st.insert(s[i]);
            }
            ret += st.size();
        }
        return ret;
    }
};

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<pair<int, int>> idx(26, {-1, -1});
        int n = s.length(), ret = 0;
        for (int i = 0; i < n; ++i) {
            if (idx[s[i] - 'a'].first == -1)
                idx[s[i] - 'a'] = {i, i};
            else
                idx[s[i] - 'a'].second = i;
        }
        for (int i = 0; i < 26; ++i) {
            if (idx[i].first != idx[i].second) {
                unordered_set<char> st(begin(s) + idx[i].first + 1, begin(s) + idx[i].second);
                ret += st.size();
            }
        }
        return ret;
    }
};