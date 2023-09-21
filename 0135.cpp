// Second time
/*
    Find the peak and valley
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        int ret = 1, up = 0, down = 0, peak = 0;
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i - 1]) {
                down = 0;
                up++;
                peak = up;
                ret += up + 1;  // Add original one
            } else if (ratings[i] < ratings[i - 1]) {
                up = 0;
                down++;
                ret += down;
                if (down > peak)
                    ret++;
            } else {
                up = 0;
                down = 0;
                peak = 0;
                ret++;
            }
        }
        return ret;
    }
};

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), i = 1, peak = 0, valley = 0, ret = n;
        while (i < n) {
            peak = 0;
            while (i < n && ratings[i] > ratings[i - 1]) {
                peak++;
                ret += peak;
                i++;
            }
            valley = 0;
            while (i < n && ratings[i] < ratings[i - 1]) {
                valley++;
                ret += valley;
                i++;
            }
            while (i < n && ratings[i] == ratings[i - 1]) {
                i++;
            }
            // The peak have been count twice, only remain the maximum
            ret -= min(peak, valley);
        }
        return ret;
    }
};

/*
    Calculate from two ends and another space 
    T: O(n)/S: O(n)
*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> ret(n, 1);
        // Compare to left element
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                ret[i] = ret[i - 1] + 1;
            }
        }
        // Compare to right element, notice to check the numbers of candies as well
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1] && ret[i] <= ret[i + 1]) {
                ret[i] = ret[i + 1] + 1;
            }
        }
        return accumulate(ret.begin(), ret.end(), 0);
    }
};


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
                if (down > peak) {  //Check we need to add one on the peek or not
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