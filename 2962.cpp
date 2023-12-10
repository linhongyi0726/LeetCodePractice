// First time
/*
    Another thought, calculate the total sub-array first,
    then subtract the number of sub-array which contain < k times maximum element
    [1]     -> [1]
    [1,2]   -> [2], [1,2] ([1] has been counted already)
    [1,2,3] -> [3], [2,3], [1,2,3]

    T: O(n)/S: O(1)
*/
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), cnt = 0, l = 0;
        int mx = *max_element(nums.begin(), nums.end());
        long long ret = (long long)(n + 1) * n / 2;
        for (int r = 0; r < n; ++r) {
            if (nums[r] == mx)
                cnt++;
            while (cnt == k) {
                if (nums[l++] == mx)
                    cnt--;
            }
            ret -= r - l + 1;
        }
        return ret;
    }
};

/*
    The same idea, but calculate the previous element before left boundary
    e.g.
    [1,3,2,3,3]
    [1,3,2,3] -> shrink left to [2,3] -> [1,3,2,3] and [3,2,3]
    [2,3,3] -> shrink left to [3] -> [1,3,2,3,3], [3,2,3,3], [2,3,3], [3,3]

    T: O(n)/S: O(1)
*/
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), cnt = 0, l = 0;
        int mx = *max_element(nums.begin(), nums.end());
        long long ret = 0;
        for (int r = 0; r < n; ++r) {
            if (nums[r] == mx)
                cnt++;
            while (cnt == k) {
                if (nums[l++] == mx)
                    cnt--;
            }
            ret += l;
        }
        return ret;
    }
};

/*
    Sliding window
    first loop to find the maximum of array,
    second loop to do sliding window to find the sub-array which has actually k times maximum element,
    then the remain elements must can be the sub-array which contain >= k times maximum element
    e.g.
    [1,3,2,3,3]
    find [1,3,2,3] -> means [1,3,2,3] and [1,3,2,3,3] must be sub-array
    shrink left boundary to find [3,2,3] -> [3,2,3] and [3,2,3,3]
    shrink left boundary and move right boundary to find [2,3,3] -> [2,3,3] and [3,3]

    T: O(n)/S: O(1)
*/
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ret = 0;
        int n = nums.size(), l = 0, cnt = 0, mx = 0;
        for (int num : nums)
            mx = max(mx, num);
        for (int r = 0; r < n; ++r) {
            if (nums[r] == mx)
                cnt++;
            while (cnt == k) {
                ret += n - r;
                if (nums[l] == mx)
                    cnt--;
                l++;
            }
        }
        return ret;
    }
};