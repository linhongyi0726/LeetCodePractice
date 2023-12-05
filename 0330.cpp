// First time
/*
    Similar concept with problem 1798
    But here if we found the next value can't make our goal number (mx+1),
    we add it to the array, and plus one patch

    T: O(nlogn)/S: O(1)
*/
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        sort(nums.begin(), nums.end());
        int ret = 0, i = 0, sz = nums.size();
        long long mx = 0;
        while (mx < n) {
            if (i < sz && nums[i] <= mx + 1) {
                mx += nums[i++];
            } else {
                // add mx+1 to the array, so that the number we can make could be extended mx+1
                mx += mx + 1;
                ret++;
            }
        }
        return ret;
    }
};