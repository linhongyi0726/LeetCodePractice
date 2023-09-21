// First time
/*
    Reduce to sub-array problem -> sliding window
    [1, 1, 4, 2, 3], x = 5
    |-----|____|--|
           just need to find the sub-array which sum is total-5
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = accumulate(nums.begin(), nums.end(), 0) - x;
        int n = nums.size(), l = 0, r = 0, ret = INT_MAX, sum = 0;
        for (; r < n; ++r) {
            sum += nums[r];
            while (l <= r && sum > target)
                sum -= nums[l++];
            if (sum == target)
                ret = min(ret, n - (r - l + 1));
        }
        return ret == INT_MAX ? -1 : ret;
    }
};

/*
    With hash map
    like two sum problem, find the suitable prefix sum that diff is the target
    T: O(n)/S: O(n)
*/
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = accumulate(nums.begin(), nums.end(), 0) - x;
        if (target == 0) return nums.size();
        int ret = INT_MAX, prefix = 0, n = nums.size();
        unordered_map<int, int> mp;  // key: prefix sum, value: index
        mp[0] = -1;
        for (int i = 0; i < n; ++i) {
            prefix += nums[i];
            if (mp.count(prefix - target))
                ret = min(ret, n - (i - mp[prefix - target]));
            mp[prefix] = i;
        }
        return ret == INT_MAX ? -1 : ret;
    }
};