// First time
/*
    1. sort by end time
    2. use binary search to find the nearest end time based on current job's start time
    dp[i] denote the maximum profits end at i time
    ex.
    [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
             |____|
       |___________________| -> the nearest end time is 0, but we need to consider job[4:5]
                         |_________|
    We need to choose maximum between the profit of last element in dp
    and the profit of doing current job

    T: O(nlogn+nlogn)/S: O(n)
*/
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        for (int i = 0; i < startTime.size(); ++i) {
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        // Here dp only can keep the job, not all of the time points because of the constraints (10^9)
        // {end, profit}
        map<int, int> dp;
        dp[0] = 0;
        for (auto& job : jobs) {
            int start = job[1], end = job[0], prof = job[2];
            auto it = prev(dp.upper_bound(start));
            // the last element in dp is already the max profit
            dp[end] = max(dp.rbegin()->second, it->second + prof);
        }
        return dp.rbegin()->second;
    }
};

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        map<int, vector<pair<int, int>>> mp;
        for (int i = 0; i < startTime.size(); ++i) {
            mp[endTime[i]].push_back({startTime[i], profit[i]});
        }
        map<int, int> dp;
        dp[0] = 0;
        for (auto& it : mp) {
            for (auto& v : it.second) {
                int start = v.first, end = it.first, prof = v.second;
                dp[end] = max(dp.rbegin()->second, prev(dp.upper_bound(start))->second + prof);
            }
        }
        return dp.rbegin()->second;
    }
};

/*
    Memoization + DP
    dp[i] denote the max profit in i jobs (jobs are sorted by start time)
    T: O(nlongn)/S: O(n)
*/
class Solution {
public:
    int helper(vector<vector<int>>& jobs, vector<int>& dp, int n, int i) {
        if (i == n) return 0;
        if (dp[i] != -1) return dp[i];
        int ndojob = helper(jobs, dp, n, i + 1);
        vector<int> v = {jobs[i][1], 0, 0};
        int idx = lower_bound(jobs.begin(), jobs.end(), v) - jobs.begin();
        int dojob = jobs[i][2] + helper(jobs, dp, n, idx);
        return dp[i] = max(ndojob, dojob);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        int n = startTime.size();
        for (int i = 0; i < n; ++i) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        vector<int> dp(n, -1);
        return helper(jobs, dp, n, 0);
    }
};

// Sorted by start time and iterate from the end
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        int n = startTime.size();
        for (int i = 0; i < n; ++i) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            vector<int> v = {jobs[i][1], 0, 0};
            int j = lower_bound(jobs.begin(), jobs.end(), v) - jobs.begin();
            // max(do job, not do job)
            dp[i] = max(jobs[i][2] + dp[j], dp[i + 1]);
        }
        return dp[0];
    }
};