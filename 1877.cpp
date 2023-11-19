// First time
/*
    sort and use 2 ptr compute the sum from each side
    There are min+max in every pair, so the sum will be minimum

    T: O(nlogn)/S: O(1)
*/
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), l = 0, r = n - 1, ret = 0;
        while (l < r) {
            ret = max(ret, nums[l++] + nums[r--]);
        }
        return ret;
    }
};