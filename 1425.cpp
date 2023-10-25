// First time
/*
    The same idea with monotonic queue + dp,
    but use heap to pop the maximum previous sum in the range
    With a little concept of sliding window

    Notice here we need to use while to pop the out of range element,
    because instead of deque, heap won't keep the index order, maybe we need to pop multiple
    T: O(nlogn)/S: O(n)
*/
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size(), ret = INT_MIN;
        // {the max sum in nums[0:i], i}
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; ++i) {
            while (!pq.empty() && pq.top().second < i - k)
                pq.pop();
            int prev = pq.empty() ? 0 : pq.top().first;
            nums[i] = max(nums[i], prev + nums[i]);
            ret = max(ret, nums[i]);
            pq.push({nums[i], i});
        }
        return ret;
    }
};

/*
    Use dp + monotonic queue (deque)
    with a little concept of sliding window

    instead of traversing the dp[i-k]...dp[i-1] every time
    use decreasing deque to keep the maximum number's index at the front,
    then use it to judge using previous sum or start a new sub-array from current nums[i]

    T: O(n)/S: O(n)
    -----
    Only use deque with the same idea
    but reuse the input nums to reduce space complexity

    T: O(n)/S: O(n)
*/
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size(), ret = INT_MIN;
        vector<int> dp(n, 0);
        // record the possible idx from large to small
        deque<int> dq;
        for (int i = 0; i < n; ++i) {
            if (!dq.empty() && dq.front() < i - k)
                dq.pop_front();
            int prev = max(0, dq.empty() ? 0 : dp[dq.front()]);
            dp[i] = prev + nums[i];
            ret = max(ret, dp[i]);
            while (!dq.empty() && dp[dq.back()] <= dp[i])
                dq.pop_back();
            dq.push_back(i);
        }
        return ret;
    }
};

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size(), ret = INT_MIN;
        // record the possible idx from large to small
        deque<int> dq;
        for (int i = 0; i < n; ++i) {
            // remove the index which out of range
            if (!dq.empty() && dq.front() < i - k)
                dq.pop_front();
            // choose the maximunm number in the range
            // if less than 0, just give up previous sum
            /*
            int prev = dq.empty() ? 0 : nums[dq.front()];
            nums[i] = max(nums[i], prev + nums[i]);
            */
            int prev = max(0, dq.empty() ? 0 : nums[dq.front()]);
            nums[i] += prev;
            ret = max(ret, nums[i]);
            // remove the impossible candidate (less then the new number)
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            // add the new candidate
            dq.push_back(i);
        }
        return ret;
    }
};

/*
    DP -> TLE!
    dp[i] denote the max sum of nums[0:i-1]
    dp[i] = nums[i] + max(dp[i - k], ..., dp[i - 1])
    T: O(n^2)/S: O(n)
*/
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size(), ret = INT_MIN;
        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i) {
            dp[i] = nums[i];
            for (int j = i - 1; j >= 0 && j >= i - k; --j) {
                dp[i] = max(dp[i], dp[j] + nums[i]);
            }
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};