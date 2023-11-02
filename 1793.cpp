// First time
/*
    2 ptr with greedy
    We need to let the sub-array size and the elements inside larger
    -> start at index k, then expand to the direction which element is larger
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size(), l = k, r = k, ret = nums[k], mn = nums[k];
        while (l > 0 || r < n - 1) {
            if (l == 0 || nums[l - 1] < nums[r + 1]) {
                mn = min(mn, nums[++r]);
            } else if (r == n - 1 || nums[l - 1] >= nums[r + 1]) {
                mn = min(mn, nums[--l]);
            }
            ret = max(ret, mn * (r - l + 1));
       }
       return ret;
    }
};