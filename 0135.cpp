// First time
/*
    Treat it like peak and valley
    *Note to save the current peak, it is used to compare to "down" to decide to update peak or not
    If down > peak, it will become a more deep valley
    [1 , 3 , 2 , 2 , 1]
         2
       /   \
     1       1 - 2     => total = 7
                   \
                    1
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        int ans = 1, up = 0, down = 0, peak = 0;
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i-1]) {
                down = 0;
                peak = ++up;
                ans += (up + 1);
            } else if (ratings[i] < ratings[i-1]) {
                up = 0;
                down++;
                if (down > peak) {
                    ans += (down + 1);
                } else {
                    ans += down;
                }
            } else {
                up = down = peak = 0;
                ans += 1;
            }
        }
        return ans;
    }
};

/*
    Compare from forward and backward
    T: O(n)/S: O(n)
*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> ans(n, 1);
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i-1] && ans[i] <= ans[i-1]) {
                ans[i] = ans[i-1]+1;
            }
            if (ratings[n-1-i] > ratings[n-i] && ans[n-1-i] <= ans[n-i]) {
                ans[n-1-i] = ans[n-i]+1;
            }
        }
        return accumulate(ans.begin(), ans.end(), 0);
    }
};