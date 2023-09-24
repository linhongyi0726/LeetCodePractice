// First time
/*
    sort by length then check the length of word chain
    Iterative to choose the character that we want to remove,
    then check the combined string is in hash map or not -> yes, length can +1
    T: O(nlogn)/S: O(n)
*/
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](string &a, string &b){return a.length() < b.length();});
        unordered_map<string, int> dp;
        int ret = 0;
        for (string word : words) {
            dp[word] = 1;
            for (int i = 0; i < word.length(); ++i) {
                /*
                // use erase to directly remove character
                string tmp = word;
                tmp.erase(i, 1);
                */
                string pre = word.substr(0, i) + word.substr(i + 1);
                if (dp.count(pre))
                    dp[word] = max(dp[word], dp[pre] + 1);
            }
            ret = max(ret, dp[word]);
        }
        return ret;
    }
};