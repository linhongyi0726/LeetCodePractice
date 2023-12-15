// First time
/*
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), mx2 = 0, mx1 = 0;
        for (int num : nums) {
            if (num > mx1) {
                mx2 = mx1;
                mx1 = num;
            } else if (num > mx2) {
                mx2 = num;
            }
        }
        return (mx2 - 1) * (mx1 - 1);
    }
};

/*
    T: O(nlogn)/S: O(1)
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return (nums[n - 2] - 1) * (nums[n - 1] - 1);
    }
};