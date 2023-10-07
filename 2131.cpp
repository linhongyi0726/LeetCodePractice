// First time
/*
    with hash map
    T: O(n)/S: O(n)
*/
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> cnt;
        int ret = 0;
        for (string word : words) {
            string rev = word;
            reverse(rev.begin(), rev.end());
            if (cnt[rev]) {
                ret += 4;
                cnt[rev]--;
            } else {
                cnt[word]++;
            }
        }
        // check the same characters
        for (auto it : cnt) {
            if (it.second && it.first[0] == it.first[1]) {
                return ret + 2;
            }
        }
        return ret;
    }
};

/*
    use array instead of hash map
    T: O(n)/S: O(n)
*/
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        vector<vector<int>> cnt(26, vector<int>(26, 0));
        int ret = 0;
        for (string word : words) {
            int c1 = word[0] - 'a', c2 = word[1] - 'a';
            if (cnt[c2][c1]) {
                ret += 4;
                cnt[c2][c1]--;
            } else {
                cnt[c1][c2]++;
            }
        }
        for (int i = 0; i < 26; ++i) {
            if (cnt[i][i])
                return ret + 2;
        }
        return ret;
    }
};