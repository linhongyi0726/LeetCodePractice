// First time
/*
    Similar with problem 2830
    dp[i] denotes the max dollars for the end of i roads
    Use sort instead of map
    T: O(n+klongk)/S: O(n)
*/
class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        vector<long long> dp(n + 1, 0);
        sort(rides.begin(), rides.end());
        int j = 0;
        for (int i = 1; i <= n; ++i) {
            // Notice to use max() to make sure not override already counted dollars
            dp[i] = max(dp[i], dp[i-1]);
            while (j < rides.size() && rides[j][0] == i) {
                int start = rides[j][0], end = rides[j][1], tip = rides[j][2];
                dp[end] = max(dp[end], dp[start] + end - start + tip);
                ++j;
            }
        }
        return dp[n];
    }
};

/*
    dp[i] denotes the max dollars for the end of i roads
    1, 2, 3, 4 ... n-1, n
   |_______|
         |____________|
    ^     ^
  start   end
  T: O(n+m)/S: O(n+m)
*/
class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        vector<long long> dp(n + 1, 0);
        unordered_map<int, vector<pair<int, int>>> mp;
        for (auto& ride : rides)
            mp[ride[1]].push_back({ride[0], ride[2]});
        for (int end = 1; end <= n; ++end) {
            dp[end] = dp[end - 1];
            for (auto& [start, tip] : mp[end])
                dp[end] = max(dp[end], dp[start] + end - start + tip);
        }
        return dp[n];
    }
};

/*
    dp[i] denotes the max dollars for the start of i roads
    1, 2, 3 ... n-2, n-1, n
                |__________|
            |______|
                 ^        ^
               start     end
  T: O(n+m)/S: O(n+m)
*/
class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        vector<long long> dp(n + 1, 0);
        unordered_map<int, vector<pair<int, int>>> mp;
        for (auto& ride : rides)
            mp[ride[0]].push_back({ride[1], ride[2]});
        for (int start = n - 1; start >= 1; --start) {
            dp[start] = dp[start + 1];
            for (auto& [end, tip] : mp[start])
                dp[start] = max(dp[start], dp[end] + end - start + tip);
        }
        return dp[1];
    }
};