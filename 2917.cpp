// First time
/*
    set the satisfied bit in the return value
    T: O(n*32)/S: O(1)
*/
class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int n = nums.size(), ret = nums[0];
        ret = 0;
        for (int i = 0; i <= 31; ++i) {
            int cnt = 0;
            for (int num : nums) {
                if (num & (1 << i))
                    cnt++;
            }
            if (cnt >= k)
                ret |= (1 << i); 
        }
        return ret;
    }
};