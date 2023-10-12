// First time
/*
    Choose start index and binary search to find the end index
    the continuous array must be {nums[start] ... nums[start] + n-1}
    e.g.
    [1, 2, 3, 5, 6]
     s           e -> target=5, so e-1

    T: O(nlogn)/S: O(1)
*/
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        int uniquelen = nums.size(), ret = INT_MAX;
        for (int start = 0; start < uniquelen; ++start) {
            int target = nums[start] + n - 1;
            int end = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
            end--;
            ret = min(ret, n - (end - start + 1));
        }
        return ret;
    }
};

/*
    Use sliding window to count the continuous numbers,
    then return the amount of non-continuous numbers
    *Need to sort and skip the same numbers

    The difference between the maximum element and the minimum element in nums equals nums.length - 1.
    e.g.
    [1, 2, 3, 5, 6], n = 5
     l        r    -> nums[r]-nums[l] = 4 = n-1
     l           r -> nums[r]-nums[l] = 5 > n-1 -> shrink the window

    T: O(nlogn)/S: O(1)
*/
class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0, r = 0, n = nums.size();
        // move the unique number to the front, or use STL unique() to remove
        // nums.erase(unique(nums.begin(), nums.end()), nums.end());
        for (l = 0, r= 0; r < n; ++r) {
            if (nums[l] != nums[r])
                swap(nums[++l], nums[r]);
        }
        int uniquelen = l + 1, cnt = 0;
        for (l = 0, r = 0; r < uniquelen; ++r) {
            while (l < uniquelen && nums[r] - nums[l] > n - 1) {
                l++;
            }
            cnt = max(cnt, r - l + 1);
        }
        return n - cnt;
    }
};