// First time
/*
    1 pass
    T: O(n)/S: O(n)
*/
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<vector<int>> ret;
        for (auto num : nums) {
            if (ret.size() == mp[num])
                ret.push_back({});
            ret[mp[num]].push_back(num);
            mp[num]++;
        }
        return ret;
    }
};

/*
    2 pass
    T: O(n)/S: O(n)
*/
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = 0;
        for (auto num : nums) {
            mp[num]++;
            n = max(n, mp[num]);
        }
        vector<vector<int>> ret(n);
        for (auto [num, cnt] : mp) {
            for (int i = 0; i < cnt; ++i) {
                ret[i].push_back(num);
            }
        }
        return ret;
    }
};