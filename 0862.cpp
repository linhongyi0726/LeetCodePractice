// First time
/*
    Similar with problem 209 -> positive integers only

    prefix sum + deque
    T: O(n)/S: O(n)
*/
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int ret=INT_MAX, n=nums.size();
        vector<long long> prefix(n+1, 0);
        for (int i=0; i<n; ++i) prefix[i+1]=prefix[i]+nums[i];
        deque<int> dq;
        for (int i=0; i<n+1; ++i) {
            while (!dq.empty() && prefix[i]-prefix[dq.front()] >= k) {
                ret=min(ret, i-dq.front());
                dq.pop_front();
            }
            while (!dq.empty() && prefix[i] <= prefix[dq.back()]) dq.pop_back();
            dq.push_back(i);
        }
        return ret==INT_MAX?-1:ret;
    }
};

/*
    prefix sum + min heap
    T: O(nlogn)/S: O(n)
*/
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int ret=INT_MAX, n=nums.size();
        vector<long long> prefix(n+1, 0);
        for (int i=0; i<n; ++i) prefix[i+1]=prefix[i]+nums[i];
        // *Notice here we can't directly use partial_sum() because of overflow, partial_sum() default is int
        // partial_sum(nums.begin(), nums.end(), prefix.begin()+1);
        auto comp=[&](int i, int j) {return prefix[i]>prefix[j];};
        priority_queue<int, vector<int>, decltype(comp)> pq(comp);
        for (int i=0; i<n+1; ++i) {
            while (!pq.empty() && prefix[i]-prefix[pq.top()] >= k) {
                ret=min(ret, i-pq.top());
                pq.pop();
            }
            pq.push(i);
        }
        return ret==INT_MAX?-1:ret;
    }
};