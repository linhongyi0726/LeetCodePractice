// First time
/*
    Because the array is non-decreasing order
    [2, 4, 6, 8]
    the diff at 4 is [2, 0, 2, 4]
    and the diff at 6 can be [2+(6-4), 0+(6-4), 2-(6-4), 8-(6-4)]
    So if we know the first element's sum, we can calculate the others

    T: O(n)/S: O(1)
*/
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n, 0);
        // calculate the first element
        for (int i = 0; i < n; ++i) {
            ret[0] += nums[i] - nums[0];
        }
        for (int i = 1; i < n; ++i) {
            int diff = nums[i] - nums[i - 1];
            ret[i] = ret[i - 1] + diff * i - diff * (n - i);
        }
        return ret;
    }
};

/*
    The same concept with prefix sum solution,
    but use variable instead of array to reduce the space complexity

    T: O(n)/S: O(1)
*/
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size(), lsum = 0, rsum = accumulate(nums.begin(), nums.end(), 0);
        vector<int> ret(n, 0);
        for (int i = 0; i < n; ++i) {
            ret[i] = (nums[i] * i - lsum) + (rsum - nums[i] * (n - i));
            lsum += nums[i];
            rsum -= nums[i];
        }
        return ret;
    }
};

/*
    [2, 4, 6, 8]
    for 6 (idx 2), the sum of absolute differences is
    |2-6|+|4-6|+|6-6|+|8-6|
    = (6-2)+(6-4)+(6-6)+(8-6)
    = (6*3-(2+4+6))+(8-6*1)
    -> we can separate the problem to left and right part
    left: the number less than target -> target-number
    right: the number greater than target -> number-target
    And we can use prefix sum to calculate the sum of left and right part

    T: O(n)/S: O(n)
*/
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        vector<int> ret(n, 0);
        for (int i = 1; i <= n; ++i) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
        for (int i = 0; i < n; ++i) {
            int l = nums[i] * (i + 1) - (prefix[i + 1] - prefix[0]);
            int r = (prefix[n] - prefix[i + 1]) - nums[i] * (n - 1 - i);
            ret[i] = l + r;
        }
        return ret;
    }
};