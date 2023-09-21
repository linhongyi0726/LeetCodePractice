// First time
/*
    After sorting, we must select student from small to large, so the selected number = i+1
    If first student isn't 0, it means we can select no one
    And select all student must be one of the answer
    T: O(nlogn)/S: O(1)
*/
class Solution {
public:
    int countWays(vector<int>& nums) {
        int ret = 1, flag = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0)
                flag = 1;
            if (i < nums.size() - 1 && i + 1 > nums[i] && i + 1 < nums[i + 1])
                ret++;
        }
        ret++;
        return flag ? ret-1 : ret;
    }
};

// optimize
class Solution {
public:
    int countWays(vector<int>& nums) {
        int ret = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        if (nums[0] != 0) ret = 1;  // Select no one
        for (int i = 0; i < n; ++i) {
            if (i < n - 1 && i + 1 > nums[i] && i + 1 < nums[i + 1])
                ret++;
        }
        ret++;  // Select all
        return ret;
    }
};