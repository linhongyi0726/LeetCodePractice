// First time
/*
    Similar with problem 2008
    dp[i] denotes the max profit for the end of i-1 houses
    Use sort instead of map
    T: O(n+klongk)/S: O(n)
*/
class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        vector<int> dp(n + 1, 0);
        sort(offers.begin(), offers.end());
        int j = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = max(dp[i], dp[i-1]);
            while (j < offers.size() && offers[j][0] + 1 == i) {
                int start = offers[j][0] + 1, end = offers[j][1] + 1, gold = offers[j][2];
                dp[end] = max(dp[end], dp[start - 1] + gold);
                ++j;
            }
        }
        return dp[n];
    }
};

/*
    dp[i] denotes the max profit for the end of i-1 houses
    i denotes the number of houses we need to sell

    dp[end] = max(dp[end], dp[start - 1] + val)
    0, 1, 2, 3, 4 ... n-1, n
   |_____|     |____________|
      |________|
                ^          ^
              start       end
    T: O(n+m)/S: O(n+m)
*/
class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        vector<int> dp(n + 1, 0);
        unordered_map<int, vector<pair<int, int>>> mp;
        for (auto& offer : offers)
            mp[offer[1] + 1].push_back({offer[0] + 1, offer[2]});
        for (int end = 1; end < dp.size(); ++end) {
            dp[end] = dp[end - 1];
            for (auto& [start, val] : mp[end])
                dp[end] = max(dp[end], dp[start - 1] + val);
        }
        return dp[n];
    }
};

class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        vector<int> dp(n + 1, 0);
        unordered_map<int, vector<pair<int, int>>> mp;
        for (auto& offer : offers) mp[offer[1]].push_back({offer[0], offer[2]});
        for (int end = 1; end < dp.size(); ++end) {
            dp[end] = dp[end - 1];
            for (auto& [start, val] : mp[end - 1]) dp[end] = max(dp[end], dp[(start + 1) - 1] + val);
        }
        return dp[n];
    }
};

/*
    Memoization + DP -> treat it like Knapsack dp
    dp[i] denotes the max profit which start from i offers

    Iterative all offers then check we need to pick it or not
    -> dp[0] will be the answer for all offers

    T: O(nlogn)/S: O(n)
*/
class Solution {
public:
    int helper(vector<vector<int>>& offers, vector<int>& dp, int idx) {
        if (idx == offers.size()) return 0;
        if (dp[idx] != -1) return dp[idx];
        int notsell = helper(offers, dp, idx + 1);
        int m = offers.size(), nextidx = m, l = 0, r = m - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (offers[mid][0] > offers[idx][1]) {
                r = mid - 1;
                nextidx = mid;
            } else {
                l = mid + 1;
            }
        }
        int sell = offers[idx][2] + helper(offers, dp, nextidx);
        return dp[idx] = max(notsell, sell);
    }
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(), offers.end());
        vector<int> dp(offers.size(), -1);
        return helper(offers, dp, 0);
    }
};

/*
    brute-force -> TLE
    dp[i] denote the max profit for the end of i-1 houses
    count the profit from smaller start to bigger
    T: O(n^2)/S: O(n)
*/
class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        vector<int> dp(n+1, 0);
        int ans=0;
        sort(offers.begin(), offers.end());
        for (int i=0; i<offers.size(); ++i) {
            int start=offers[i][0]+1, end=offers[i][1]+1, gold=offers[i][2];
            dp[end]=max(dp[end], dp[start-1]+gold);
            ans=max(ans, dp[end]);
            while (end+1<dp.size()) {
                if (dp[++end]<dp[start-1]+gold) dp[end]=dp[start-1]+gold;
                else break;
            }
        }
        return ans;
    }
};