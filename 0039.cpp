// First time
/*
    Backtracking
    Use recursion to DFS
    T: O(2^n)/S: O(1)
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