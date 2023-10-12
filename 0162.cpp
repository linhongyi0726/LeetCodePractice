// First time
/*
    The same with problem 852

    [0 ... n-2, n-1)
    [          ]
    Because we need to check m+1
    -> only do BS in [0, n-2]

    T: O(logn)/S: O(1)
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] < nums[m + 1])
                l = m + 1;
            else
                r = m;
        }
        return l;
    }
};