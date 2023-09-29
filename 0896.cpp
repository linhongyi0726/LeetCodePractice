// First time
/*
    1 pass
    To check the trends of whole array is the same
    (ignore the same element nearby)
    T: O(n)/S: O(1)
*/
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool increase = true, decrease = true;
        for (int i = 1; i < nums.size(); ++i) {
            increase = increase && nums[i] >= nums[i - 1] ? true : false;
            decrease = decrease && nums[i] <= nums[i - 1] ? true : false;
        }
        return increase || decrease;
    }
};

// Use bitwise operator
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool increase = true, decrease = true;
        for (int i = 1; i < nums.size(); ++i) {
            increase &= nums[i] >= nums[i - 1];
            decrease &= nums[i] <= nums[i - 1];
        }
        return increase || decrease;
    }
};

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if (nums.size() < 3)
            return true;
        bool increase = false, decrease = false;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1])
                increase = true;
            else if (nums[i] < nums[i - 1])
                decrease = true;
            if (increase && decrease)
                return false;
        }
        return true;
    }
};

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        if (nums.back() >= nums.front()) {
            for (int i = 1; i < n; ++i) {
                if (nums[i] < nums[i - 1])
                    return false;
            }
        } else {
            for (int i = 1; i < n; ++i) {
                if (nums[i] > nums[i - 1])
                    return false;
            }
        }
        return true;
    }
};