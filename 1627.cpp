// Fist time
/*
    T: O(mn)/S: O(1)
*/
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0, tmp = 0;
        int m = accounts.size(), n = accounts[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j)
                tmp += accounts[i][j];
            ans = max(ans, tmp);
            tmp = 0;
        }
        return ans;
    }
};