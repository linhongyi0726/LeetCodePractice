// First time
/*
    backtracking
    T: O(2^n)/S: O(2^n)
*/
// e.g. [1,2,3]: [], [1], [12], [123], [13], [2], [23], [3]
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> sub;
        dfs(nums, ret, sub, 0);
        return ret;
    }
    void dfs(vector<int> &nums, vector<vector<int>> &ret, vector<int> &sub, int i) {
        ret.push_back(sub);
        for (int j = i; j < nums.size(); ++j) {
            sub.push_back(nums[j]);
            dfs(nums, ret, sub, j + 1);
            sub.pop_back();
        }
    }
};

// e.g. [1,2,3]: [123], [12], [13], [1], [23], [2], [3], []
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> sub;
        dfs(nums, ret, sub, 0);
        return ret;
    }
    void dfs(vector<int> &nums, vector<vector<int>> &ret, vector<int> &sub, int i) {
        if (i == nums.size()) {
            ret.push_back(sub);
            return;
        }
        // choose nums[i]
        sub.push_back(nums[i]);
        dfs(nums, ret, sub, i + 1);
        // not choose nums[i]
        sub.pop_back();
        dfs(nums, ret, sub, i + 1);
    }
};

/*
    []:        []
    [1]:       [], [1]
    [1, 2]:    [], [1], [2], [1, 2]
    [1, 2, 3]: [], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]
    The new elements will append at all the previous subsets

    There are 2^n number of subset
    T: O(2^n)/S: O(1)
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret = {{}};
        for (int i = 0; i < nums.size(); ++i) {
            int n = ret.size();
            for (int j = 0; j < n; ++j) {
                auto tmp = ret[j];
                tmp.push_back(nums[i]);
                ret.push_back(tmp);
            }
        }
        return ret;
    }
};