// First time
/*
    1 pass
    Record the first max and the second max number
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max1 = 0, max2 = 0, ret = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > max1) {
                max2 = max1;
                max1 = nums[i];
                ret = i;
            } else if (nums[i] > max2){
                max2 = nums[i];
            }
        }
        return max1 >= max2 * 2 ? ret : -1;
    }
};

/*
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end()), ret = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (mx == nums[i]) ret = i;
            else if (mx < nums[i] * 2) return -1;
        }
        return ret;
    }
};