// Second time
/*
    the backtracking swap is used to recover nums order to avoid affecting next recursion
    [a,b,c] -> [a,c,b] -> [a,b,c] (for next recursion)
    T: O(n*n!)/S: O(n*n!)
*/
class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>>& ans, int idx) {
        if (idx==nums.size()) {
            ans.push_back(nums);
            return;
        }
        for (int i=idx; i<nums.size(); ++i) {
            swap(nums[i], nums[idx]);
            helper(nums, ans, idx+1);
            swap(nums[i], nums[idx]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(nums, ans, 0);
        return ans;
    }
};

/*
    Use build-in STL function to find next permutation
*/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        ans.push_back(nums);
        while (next_permutation(nums.begin(),nums.end())) {
            ans.push_back(nums);
        }
        return ans;
    }
};


// First time
/*
    Permutation
    Backtracking
    1. swap to each other
        T: O(n*n!)/S: O(n!)
    2. insert number in every possible positions
        T: O(n*n!)/S: O(n!)
*/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        dfs(nums, ans, 0);
        return ans;
    }
    void dfs(vector<int>& nums, vector<vector<int>>& ans, int cur) {
        if (cur == nums.size()) {ans.push_back(nums); return;}
        for (int i = cur; i < nums.size(); ++i) {
            swap(nums[cur], nums[i]);
            dfs(nums, ans, cur+1);
            swap(nums[cur], nums[i]);   // swap back to previous (backtracking)
        }
    }
};

/*
    Insert nums[i] into ans, it will be in the front or back of origin number in ans
    Until no number remain in nums

    nums: [1, 2, 3]
    ans:
    -> [1] and remain [2], [3]
    -> [2] in the front:    [1, 2]
           in the back:     [2, 1]
        remain [3]
    -> [3] in the front:    [3, 1, 2], [3, 2, 1]
           in the middle:   [1, 3, 2], [2, 3, 1]
           in th back:      [1, 2, 3], [2, 1, 3]
        no remain
*/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> perm;
        dfs(nums, ans, perm, 0);
        return ans;
    }
    void dfs(vector<int>& nums, vector<vector<int>>& ans, vector<int>& perm, int cur) {
        if (cur == nums.size()) {ans.push_back(perm); return;}
        for (int i = 0; i <= perm.size(); ++i) {
            perm.insert(perm.begin()+i, nums[cur]);
            dfs(nums, ans, perm, cur+1);
            perm.erase(perm.begin()+i);
        }
    }
};