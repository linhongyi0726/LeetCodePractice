// First time
/*
    [1, 1, 2, 2, 3]
                 |  1 times
                 v
    [1, 1, 2, 2, 2]
           |  |  |  3 times
           v  v  v
    [1, 1, 1, 1, 1]

    T: O(n)/S: O(1)
*/
class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ret = 0, pre = nums[0];
        for (int i = 0; i < n; ++i) {
            if (nums[i] != pre) {
                ret += n - i;
                pre = nums[i];
            }
        }
        return ret;
    }
};

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ret = 0;
        for (int i = n - 1; i > 0; --i) {
            if (nums[i] != nums[i - 1]) {
                ret += n - i;
            }
        }
        return ret;
    }
};