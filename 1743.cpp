// First time
/*
    Use hash map to store the adjacent pairs,
    then choose the number which only has one adjacent to be the start

    T: O(n)/S: O(n)
*/
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size();
        unordered_map<int, vector<int>> mp;
        vector<int> ret(n + 1, 0);
        for (auto adj : adjacentPairs) {
            mp[adj[0]].push_back(adj[1]);
            mp[adj[1]].push_back(adj[0]);
        }
        for (auto it : mp) {
            if (it.second.size() == 1) {
                ret[0] = it.first;
                ret[1] = it.second[0];
                break;
            }
        }
        for (int i = 1; i < n; ++i) {
            for (int j : mp[ret[i]]) {
                if (j != ret[i - 1])
                    ret[i + 1] = j;
            }
        }
        return ret;
    }
};