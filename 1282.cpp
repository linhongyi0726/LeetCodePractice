// First time
/*
    Hash map (key: group size, value: member of group)
    1 pass approach
    fill in the map and check the size is full at the same time
    T: O(n)/S: O(n)
*/
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> mp;
        vector<vector<int>> ret;
        for (int i = 0; i < groupSizes.size(); ++i) {
            mp[groupSizes[i]].push_back(i);
            if (mp[groupSizes[i]].size() == groupSizes[i]) {
                ret.push_back(mp[groupSizes[i]]);
                mp[groupSizes[i]].clear();
            }
        }
        return ret;
    }
};

/*
    2 pass
    fill in the map then pop out based on the size
    T: O(n)/S: O(n)
*/
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, stack<int>> mp;
        vector<vector<int>> ret;
        for (int i = 0; i < groupSizes.size(); ++i) {
            mp[groupSizes[i]].push(i);
        }
        for (auto &[size, s] : mp) {
            while (!s.empty()) {
                vector<int> tmp(size, 0);
                for (int i = 0; i < size; ++i) {
                    tmp[i] = s.top();
                    s.pop();
                }
                ret.push_back(tmp);
            }
        }
        return ret;
    }
};