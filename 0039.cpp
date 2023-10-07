// Second time
/*
    backtracking
    traverse all possible combinations
    T: O(2^n)/S: O(n)
*/
class Solution {
public:
    vector<vector<int>> ret;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> comb;
        dfs(candidates, target, comb, 0);
        return ret;
    }
    void dfs(vector<int>& candidates, int target, vector<int> &comb, int start) {
        if (target == 0) {
            ret.push_back(comb);
            return;
        } else if (target < 0) {
            return;
        }
        for (int i = start; i < candidates.size(); ++i) {
            comb.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], comb, i);
            comb.pop_back();    // backtracking
        }
    }
};

// transform for loop to recursion
class Solution {
public:
    vector<vector<int>> ret;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> comb;
        dfs(candidates, target, comb, 0);
        return ret;
    }
    void dfs(vector<int>& candidates, int target, vector<int> &comb, int start) {
        if (start >= candidates.size())
            return;
        if (target == 0) {
            ret.push_back(comb);
            return;
        } else if (target < 0) {
            return;
        }
        comb.push_back(candidates[start]);
        dfs(candidates, target - candidates[start], comb, start);
        comb.pop_back();
        dfs(candidates, target, comb, start + 1);
    }
};

/*
    DP -> also a brute-force because we need to traverse all combinations
    *Notice to iterative candidates first to avoid the duplication answer
    T: O(n^3)/S: O(n^3)
*/
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> dp(target + 1);
        dp[0] = {{}};
        for (int num : candidates) {
            for (int i = num; i <= target; ++i) {
                for (auto v : dp[i - num]) {
                    v.push_back(num);
                    dp[i].push_back(v);
                }
            }
        }
        return dp[target];
    }
};


// First time
/*
    Backtracking
    Use recursion to DFS
    T: O(2^n)/S: O(n)
*/
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        // sort(candidates.begin(), candidates.end());
        dfs(candidates, target, ans, comb, 0);
        return ans;
    }
    void dfs(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& comb, int idx) {
        if (target == 0) {ans.push_back(comb); return;}
        // else if (target < 0) return;

        for (int i = idx; i < candidates.size(); ++i) {
            if (candidates[i] <= target) {
                comb.push_back(candidates[i]);
                dfs(candidates, target-candidates[i], ans, comb, i);
                comb.pop_back();    // leave position for next candidate (back to previous)
            }
        }
    }
};

/*
    DP
*/
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> dp(target+1);
        dp[0] = {{}};
        for (int candidate : candidates) {
            for (int i = candidate; i < target+1; ++i) {
                for (auto v : dp[i-candidate]) {
                    v.push_back(candidate);
                    dp[i].push_back(v);
                }
            }
        }
        return dp[target];
    }
};

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> dp(target+1);
        dp[0] = {{}};
        sort(candidates.begin(), candidates.end());
        for (int i = 1; i < target+1; ++i) {
            for (int candidate : candidates) {
                if (i == candidate) dp[i].push_back({candidate});
                else if (i > candidate) {
                    for (auto v : dp[i-candidate]) {
                        // let combination increasing order to avoid duplication
                        if (v.back() <= candidate) {
                            v.push_back(candidate);
                            dp[i].push_back(v);
                        }
                    }
                }
            }
        }
        return dp[target];
    }
};

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> dp(target+1);
        dp[0] = {{}};
        set<vector<int>> s;
        for (int i = 1; i < target+1; ++i) {
            for (int candidate : candidates) {
                if (i == candidate) dp[i].push_back({candidate});
                else if (i > candidate) {
                    for (auto v : dp[i-candidate]) {
                        v.push_back(candidate);
                        sort(v.begin(),v.end());
                        s.insert(v);
                    }
                }
            }
            for (auto v : s) dp[i].push_back(v);
            s.clear();
        }
        return dp[target];
    }
};