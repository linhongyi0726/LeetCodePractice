// First time
/*
    total sum = left sum + pivot value + right sum
    If there is a pivot, left sum == right sum -> total sum = 2*left sum + pivot value
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        // for (int num : nums) sum+=num;
        int sum_l = 0;
        for (int i=0; i<nums.size(); ++i) {
            if (sum==(2*sum_l+nums[i])) return i;
            sum_l+=nums[i];
        }
        return -1;
    }
};