// First time
/*
    T: O(n)/S: O(26)
*/
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int ret = 0;
        vector<int> cnt(26, 0);
        for (char c : chars)
            cnt[c - 'a']++;
        for (int i = 0; i < words.size(); ++i) {
            vector<int> tmp = cnt;
            int j = 0, n = words[i].length();
            for (; j < n; ++j) {
                if (--tmp[words[i][j] - 'a'] < 0)
                    break;
            }
            if (j == n)
                ret += n;
        }
        return ret;
    }
};