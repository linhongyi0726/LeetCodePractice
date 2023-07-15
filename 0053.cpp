// Second time
/*
    dp[i] means the max array sum which ends in index i
    ans means the max sum so far
    T: O(n)/S: O(n)
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), ans = nums[0];
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = max(nums[i], dp[i-1]+nums[i]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

/*
    Optimize -> greedy: Kadane's Algorithm
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            // cur = cur <= 0 ? nums[i] : cur+nums[i];
            cur = max(nums[i], cur+nums[i]);
            ans = max(ans, cur);
        }
        return ans;
    }
};

/*
    Another greedy: calculate the current max/min of sum
    If minsum<0, we don't want to calculate it, so maxsum = max(maxsum, sum-minsum)
    else minsum>=0, we can keep it, so maxsum = max(maxsum, sum)
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int minsum = nums[0];
        int maxsum = nums[0];
        int sum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            sum += nums[i];
            if (minsum < 0) maxsum = max(maxsum, sum-minsum);
            else maxsum = max(maxsum, sum);
            minsum = min(minsum, sum);
        }
        return maxsum;
    }
};


// First time
/*
    1. Brute-force
        T: O(n^2)/S: O(1)
    2. Greedy: Kadane's Algorithm or use moving window
        T: O(n)/S: O(1)
    3. DP
        T: O(n)/S: O(n) -> T: O(n)/S: O(1)
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int ans = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            sum = (sum + nums[i]) > nums[i] ? (sum + nums[i]) : nums[i];
            ans = ans > sum ? ans : sum;
        }
        return ans;
    }
};