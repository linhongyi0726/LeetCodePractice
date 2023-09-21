// First time
/*
    Binary search to find the times that the machines need to be operated (the number of alloys can be produced)
    *Notice the boundary of right in binary search
    and the integer overflow when we guess too large "times" at computing "pay"
    T: O(logm*n*k)/S: O(1)
*/
class Solution {
public:
    bool check(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost, int times) {
        for (int i = 0; i < k; ++i) {
            long long pay = 0;
            for (int j = 0; j < n; ++j) {
                long long require = (long long)composition[i][j] * times - stock[j];
                if (require > 0)
                    pay += require * cost[j];
            }
            if (pay <= budget)
                return true;
        }
        return false;
    }
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        // r need to consider max of stock + max of budget, or directly set to INT_MAX
        int l = 0, r = 1e8 * 2;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (check(n, k, budget, composition, stock, cost, m))
                l = m + 1;
            else
                r = m - 1;
        }
        // return l-1;
        return r;
    }
};

/*
    Brute-force -> TLE
    Calculate all number of alloys of every machines
    T: O(nk*budget)/S: O(1)
*/
class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int ret = 0;
        for (int i = 0; i < k; ++i) {
            vector<int> com = composition[i];
            vector<int> tmp = stock;
            int times = 0, pay = 0;
            while (1) {
                times++;
                for (int j = 0; j < n; ++j) {
                    if (tmp[j] >= com[j]) {
                        tmp[j] -= com[j];
                    } else {
                        pay += cost[j] * (com[j] - tmp[j]);
                        tmp[j] = 0;
                    }
                }
                if (pay > budget) {
                    break;
                } else {
                    ret = max(ret, times);
                }
            }
        }
        return ret;
    }
};