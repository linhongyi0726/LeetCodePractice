// Third time
/*
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l=0, r=0;
        while (r<nums.size()) {
            if (nums[r]==nums[l]) r++;
            else swap(nums[r++], nums[++l]);
        }
        return l+1;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l=0, r=0;
        for (; r<nums.size()-1; ++r) {
            if (nums[r]!=nums[r+1]) nums[++l]=nums[r+1];
        }
        return l+1;
    }
};


// Second time
/*
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l=0;
        for (int r=0; r<nums.size(); ++r) {
            if (nums[l] != nums[r]) swap(nums[++l], nums[r]);
            // if (nums[l] != nums[r]) nums[++l] = nums[r];
        }
        return l+1;
    }
};


// First time
/*
    two pointer
    Because nums is sorted, just need to assign/swap the value which is different
    *Note: l need to ++ first to make nums keep in the order
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l=0;
        for (int r=1; r<nums.size(); ++r) {
            if (nums[l]!=nums[r]) nums[++l]=nums[r];
            // if (nums[l]!=nums[r]) swap(nums[++l], nums[r]);
        }
        return l+1;
    }
};