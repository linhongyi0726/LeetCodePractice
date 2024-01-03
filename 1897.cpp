// First time
/*
    Count the amount of each characters,
    then check the amount can be separated to every words

    T: O(n)/S: O(n)
*/
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char, int> mp;
        int n = words.size();
        for (auto word : words) {
            for (char c : word) {
                mp[c]++;
            }
        }
        for (auto it : mp) {
            if (it.second % n)
                return false;
        }
        return true;
    }
};