// First time
/*
    Quick select or use STL
    (But here use standard quick select will cause TLE, there is a test case which is full of '1')

    There are two ways to implement quick select partition
    1. Lomuto Partition Scheme
    2. Hoare partition scheme

    T: O(n)/S: O(n)
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        nth_element(nums.begin(), nums.begin() + n - k, nums.end());
        return nums[n - k];
    }
};

/*
    min-heap
    T: O(klogk)/S: O(k)
    -----
    max-heap
    T: O(nlogn)/S: O(n)
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k)
                pq.pop();
        }
        return pq.top();
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        int n = nums.size();
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > n - k + 1)
                pq.pop();
        }
        return pq.top();
    }
};