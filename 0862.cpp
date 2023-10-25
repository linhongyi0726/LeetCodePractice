// Second time
/*
    2 ptr will fail because there is negative number,
    may let the sub-array getting longer when we compute the sum

    e.g. [84, -37, 32, 40, 95], k = 167
    -> r ptr will move to index 4 then the length is 5
       but [32, 40, 95] is satisfied and shorter
    -----
    Use monotonic queue (increasing deque)
    If there is a number smaller than dq.back(), means nums[dq.back()] <= 0

    nums:      [2, -1, 2, 1]
    prefix: [0, 2,  1, 3, 4]
                ^
             nums[1] is -1 -> we don't want this, it will let our sub-array longer

    We only care the number <= 0 to be the start of sub-array instead of being the end of sub-array,
    because the shorter length of sub-array must be compute in the previous loop
    (previous loop must satisfy the prefix sum diff >= k if current loop also satisfy)

    p.s. the order we pop_back (number <= 0) and pop_front (compute the sub-array) isn't matter here

    T: O(n)/S: O(n)
*/
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size(), ret = INT_MAX;
        vector<long long> prefix(n + 1, 0);
        for (int i = 1; i < n + 1; ++i)
            prefix[i] = prefix[i - 1] + nums[i - 1];
        deque<int> dq;
        for (int i = 0; i < n + 1; ++i) {
            // ensure there isn't number <= 0 in the deque
            while (!dq.empty() && prefix[i] <= prefix[dq.back()])
                dq.pop_back();
            dq.push_back(i);
            // check the satisfied sub-array
            while (!dq.empty() && prefix[i] - prefix[dq.front()] >= k) {
                ret = min(ret, i - dq.front());
                dq.pop_front();
            }
        }
        return ret == INT_MAX ? -1 : ret;
    }
};


// First time
/*
    Similar with problem 209 -> positive integers only

    prefix sum + deque
    Use deque to simulate window, but just to record the start/end index of sub-array
    ex.[2, -1, 2, 1], k = 3
    [0, 2,  1, 3, 4]
     ^  x   ^   -> Here need to pop index 1 because of we wouldn't use '-1' to be the start of sub-array
   front   end

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
            // decrease deque/window to find the shortest sub-array
            while (!dq.empty() && prefix[i]-prefix[dq.front()] >= k) {
                ret=min(ret, i-dq.front());
                dq.pop_front();
            }
            // increase deque/window and make sure no negative number in deque
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