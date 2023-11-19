// First time
/*
    sliding window
    For every target which number will become after operating,
    it must satisfy sum + k >= target * windows size
    e.g.
       [1, 2, 4], k=5
    -> [4, 4, 4]
       (1+2+4)+5 >= 4*3

    T: O(nlogn)/S: O(1)
*/
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), l = 0, r = 0, ret = 0;
        long long sum = 0;
        for (; r < n; ++r) {
            sum += nums[r];
            while (sum + k < (long long)nums[r] * (r - l + 1))
                sum -= nums[l++];
            ret = max(ret, r - l + 1);
        }
        return ret;
    }
};

/*
    Use prefix sum to compute the sum of sub-array
    Then choose one element be target,
    and binary search the number smaller than it to compute the longest length
    (check: sum + k >= target * length)

    T: O(nlogn)/S: O(n)
*/
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ret = 0;
        vector<long long> prefix;
        prefix.push_back(0);
        for (int i = 0; i < n; ++i)
            prefix.push_back(prefix.back() + nums[i]);
        for (int i = 0; i < n; ++i) {
            ret = max(ret, bs(nums, k, i, prefix));
        }
        return ret;
    }
    int bs(vector<int>& nums, int k, int idx, vector<long long> &prefix) {
        int l = 0, r = idx, ret = 0;
        while (l <= r) {
            int m = l + (r - l) / 2;
            long long sum = prefix[idx + 1] - prefix[m];
            if (sum + k >= (long long)nums[idx] * (idx - m + 1)) {
                ret = max(ret, idx - m + 1);
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ret;
    }
};