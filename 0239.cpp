// First time
/*
    Use monotonic queue to do sliding window
    (decreasing queue)

    T: O(n)/S: O(n)
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> ret;
        for (int i = 0; i < n; ++i) {
            if (!dq.empty() && dq.front() == i - k)
                dq.pop_front();
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);
            // the windows size already be k
            if (i >= k - 1)
                ret.push_back(nums[dq.front()]);
        }
        return ret;
    }
};

/*
    The same idea with heap
    Use heap to keep the maximum number instead of using monotonic queue
    *Notice to use "while" to pop the out of range number instead of "if",
    because heap won't keep the index order (monotonic queue will)

    T: O(nlogn)/S: O(n)
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> pq;
        vector<int> ret;
        for (int i = 0; i < n; ++i) {
            while (!pq.empty() && pq.top().second <= i - k)
                pq.pop();
            pq.push({nums[i], i});
            if (i >= k - 1)
                ret.push_back(pq.top().first);
        }
        return ret;
    }
};