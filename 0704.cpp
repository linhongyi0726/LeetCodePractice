// First time
/*
    [left, right]
    T: O(logn)/S :O(1)
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int mid;
        while (r >= l) {
            mid = (l + r) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                r = mid - 1;
            else if (nums[mid] < target)
                l = mid + 1;
        }
        return -1;
    }
};

/*
    [left, right)
    T: O(logn)/S :O(1)
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size();
        int mid;
        while (r > l) {
            mid = (l + r) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                r = mid;
            else if (nums[mid] < target)
                l = mid + 1;
        }
        return -1;
    }
};