// First time
/*
    Find the first maximum, second maximum, first minimum and second minimum numbers
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int mn1 = INT_MAX, mn2 = INT_MAX, mx1 = 0, mx2 = 0;
        for (int num : nums) {
            if (num > mx1) {
                mx2 = mx1;
                mx1 = num;
            } else if (num > mx2) {
                mx2 = num;
            }
            if (num < mn1) {
                mn2 = mn1;
                mn1 = num;
            } else if (num < mn2) {
                mn2 = num;
            }
        }
        return mx1 * mx2 - mn1 * mn2;
    }
};

/*
    T: O(nlogn)/S: O(1)
*/
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return nums[n - 1] * nums[n - 2] - nums[0] * nums[1];
    }
};