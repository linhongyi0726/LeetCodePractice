// First time
/*
    We need to find the middle of every 3 piles of coins
    Use sorting to get the maximum we can choose,
    -> [S,S,S,M,L,M,L,M,L]
              ^   ^   ^
    T: O(nlogn)/S: O(1)
*/
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int ret = 0, n = piles.size();
        for (int i = n / 3; i < n; i += 2) {
            ret += piles[i];
        }
        return ret;
    }
};

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end(), greater());
        int ret = 0, n = piles.size(), i = 1;
        while (n) {
            ret += piles[i];
            i += 2;
            n -= 3;
        }
        return ret;
    }
};