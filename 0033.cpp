// First time
/*
    Because there is possibly rotated in nums, we need to find where pivot is
    nums[m] >= nums[l] : left side is sorted in ascending order (pivot is in the right side)
    nums[m] < nums[l] : right side is sorted in ascending order (pivot is in the left side)
    T :O(logn)/S: O(1)
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        while(r>=l) {
            int m = (l+r)/2;
            if (nums[m] == target) return m;
            else if (nums[m] >= nums[l]) {
                if (nums[m] > target && nums[l] <= target) r = m-1; // Check is target in left side?
                else l = m+1;
            }
            else if (nums[m] < nums[l]) {
                if (nums[m] < target && nums[r] >= target) l = m+1; // Check is target in right side?
                else r = m-1;
            }
        }
        return -1;
    }
};

/*
    Store num and index in hash map, then sort it and binary search
    * Not satisfied in time complexity
    T :O(nlogn)/S: O(n)
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        unordered_map<int,int> mp;
        for (int i = 0; i < nums.size(); ++i)
            mp[nums[i]] = i;
        sort(nums.begin(), nums.end());
        while(r>=l) {
            int m = (l+r)/2;
            if (nums[m] == target) return mp[nums[m]];
            else if (nums[m] > target) r = m-1;
            else if (nums[m] < target) l = m+1;
        }
        return -1;
    }
};