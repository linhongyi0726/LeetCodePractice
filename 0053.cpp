// First time
/*
    1. Brute-force
        T: O(n^2)/S: O(1)
    2. Greedy: use moving window
        T: O(n)/S: O(1)
    3. DP
        T: O(n)/S: O(1)
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int ans = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            sum = (sum + nums[i]) > nums[i] ? (sum + nums[i]) : nums[i];
            ans = ans > sum ? ans : sum;
        }
        return ans;
    }
};