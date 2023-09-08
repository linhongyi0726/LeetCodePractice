// First time
/*
    Create another vector to return
    T: O(n)/S: O(n)
    -----
    Because the constraints: 1 <= nums[i] <= 10^3
    Without using extra space, we can store two integer in one integer
    [0x1, 0x2, 0x3, 0x1, 0x2, 0x3] -> [0x1, 0x2, 0x3, 0x10001, 0x20002, 0x30003]
    T: O(n)/S: O(1)
*/
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        for (int i = 0; i < n; ++i) {
            // nums[n + i] = nums[i] << 10 | nums[n + i];
            nums[n + i] = nums[i] << 16 | nums[n + i];
        }
        for (int i = 0; i < n; ++i) {
            // nums[i * 2] = nums[n + i] >> 10;
            // nums[i * 2 + 1] = nums[n + i] & ((1 << 10) - 1);
            nums[i * 2] = nums[n + i] >> 16;
            nums[i * 2 + 1] = nums[n + i] & 0xFFFF;
        }
        return nums;
    }
};

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ret(2 * n, 0);
        for (int i = 0; i < n; ++i) {
            ret[2 * i] = nums[i];
            ret[2 * i + 1] = nums[n + i];
        }
        return ret;
    }
};