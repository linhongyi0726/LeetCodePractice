// First time
/*
    The same with problem 330, and similar concept with problem 1798

    T: O(nlogn)/S: O(1)
*/
class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());
        int ret = 0, i = 0, sz = coins.size();
        long long mx = 0;
        while (mx < target) {
            if (i < sz && coins[i] <= mx + 1) {
                mx += coins[i++];
            } else {
                // add mx+1 to the array, so that the number we can make could be extended mx+1
                mx += mx + 1;
                ret++;
            }
        }
        return ret;
    }
};