// First time
/*
    Use map to store group of the anagrams
    T: O(n*klogk)/S: O(n)
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;
        for (string str:strs) {
            string sorted=str;
            sort(sorted.begin(), sorted.end());
            mp[sorted].push_back(str);
        }
        for (auto it:mp) ans.push_back(it.second);
        return ans;
    }
};