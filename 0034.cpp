// Second time
/*
    T: O(logn)/S: O(1)
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int ub = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (lb == ub)
            return {-1, -1};
        return {lb, ub - 1};
    }
};


// First time
/*
    Do binary search twice to find the element >= and > target
    lower_bound(): >= , start of target array
    upper_bound(): > , end of target array + 1
    When there isn't target in nums -> lower_bound()==upper_bound()
    T: O(logn)/S: O(1)
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb=lower_bound(nums.begin(), nums.end(), target)-nums.begin();
        int ub=upper_bound(nums.begin(), nums.end(), target)-nums.begin();
        // if(lb==nums.size() && ub==nums.size())
        if (lb==ub) return {-1, -1};
        return {lb, ub-1};
    }
};

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        /*
        find ">=" target
        [5, 7, 7, 8, 8, 8, 10], target = 8
               ^  ^
               r  l
        */
        int l=0, r=nums.size()-1, m=0;
        while (l <= r) {
            m = l+(r-l)/2;
            if (nums[m] >= target) r = m-1;
            else l = m+1;
        }
        ans[0] = l;
        /*
        find ">" target
        [5, 7, 7, 8, 8, 8, 10], target = 8
                        ^  ^
                        r  l
        */
        l=0, r=nums.size()-1;
        while (l <= r) {
            m = l+(r-l)/2;
            if (nums[m] > target) r = m-1;
            else l = m+1;
        }
        ans[1] = l;
        // ">=" and ">" must not be equal
        if (ans[0] == ans[1]) return {-1, -1};
        else ans[1]--;
        return ans;
    }
};

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        // start (>=)
        int l=0, r=nums.size()-1, m=0;
        while (l <= r) {
            m = l+(r-l)/2;
            if (nums[m] < target) l = m+1;
            else {
                if (nums[m] == target) ans[0] = m;
                r = m-1;
            }
        }
        // end (>)
        l=0, r=nums.size()-1;
        while (l <= r) {
            m = l+(r-l)/2;
            if (nums[m] > target) r = m-1;
            else {
                if (nums[m] == target) ans[1] = m;
                l = m+1;
            }
        }
        return ans;
    }
};

/*
    Binary search to find any target element,
    then go forward and backward binary search to find the boundary
    [5, 7, 7, 8, 8, 8, 10], target = 8
                 ^
    [          ] m [     ]
              ^     ^
    T: O(logn)/S: O(1)
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
        int n=nums.size(), l=0, r=n-1, m=0, find=-1;
        while (l <= r) {
            m = l+(r-l)/2;
            if (nums[m] > target) r = m-1;
            else if (nums[m] < target) l = m+1;
            else {find = m; break;}
        }
        if (find != -1) {
            l = 0, r = find;
            while (l <= r) {
                m = l+(r-l)/2;
                if (nums[m] >= target) r = m-1;
                else if (nums[m] < target) l = m+1;
            }
            ans[0] = l;
            l = find+1, r = n-1;
            while (l <= r) {
                m = l+(r-l)/2;
                if (nums[m] > target) r = m-1;
                else if (nums[m] <= target) l = m+1;
            }
            ans[1] = r;
        }
        return ans;
    }
};