// First time
/*
    T: O(n)/S: (1)
*/
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i)
            nums[i] += nums[i-1];
        return nums;
    }
};