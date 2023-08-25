// First time
/*
    dp[i] denote the max profit in i houses
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