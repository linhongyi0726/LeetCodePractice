// First time
/*
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int countbit(int n) {
        int ret = 0;
        while (n) {
            n &= n-1;
            ret++;
        }
        return ret;
    }
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (countbit(i) == k)
                sum += nums[i];
        }
        return sum;
    }
};