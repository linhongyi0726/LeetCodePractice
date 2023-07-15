// First time
/*
    we can't only use nums[l++]=nums[r], because the zero need to keep in the behind
    otherwise we need to fill zero in the behind
    T: O(n)/S: O(1)
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l=0;
        for (int r=0; r<nums.size(); ++r) {
            if (nums[r] != 0) swap(nums[l++], nums[r]);
        }
    }
};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l=0;
        for (int r=0; r<nums.size(); ++r) {
            if (nums[r] != 0) nums[l++] = nums[r];
        }
        while (l < nums.size()) nums[l++] = 0;
    }
};