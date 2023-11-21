// First time
/*
    We can convert the condition
       nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
    -> nums[i] - rev(nums[i]) == nums[j] - rev(nums[j])
    And then count and check the same value in the array

    T: O(nlogk)/S: O(n) -> O(logk) for reverse the number
*/
class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        int n = nums.size(), ret = 0, mod = 1e9 + 7;
        unordered_map<int, int> cnt;
        for (int &num : nums) {
            ret = (ret + cnt[num - reverse(num)]) % mod;
            cnt[num - reverse(num)]++;
        }
        return ret;
    }
    int reverse(int num) {
        int ret = 0;
        while (num) {
            ret = ret * 10 + num % 10;
            num /= 10;
        }
        return ret;
    }
};

class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        int n = nums.size(), ret = 0, mod = 1e9 + 7;
        unordered_map<int, int> cnt;
        for (int &num : nums) {
            num -= reverse(num);
            if (cnt.count(num)) {
                ret = (ret + cnt[num]) % mod;
            }
            cnt[num]++;
        }
        return ret;
    }
    int reverse(int num) {
        int ret = 0;
        while (num) {
            ret = ret * 10 + num % 10;
            num /= 10;
        }
        return ret;
    }
};

/*
    Brute-force -> TLE
    T: O(n^2)/S: O(n)
*/
class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        int n = nums.size(), ret = 0, mod = 1e9 + 7;
        vector<int> rev(n, 0);
        for (int i = 0; i < n; ++i) {
            rev[i] = reverse(nums[i]);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] + rev[j] == nums[j] + rev[i])
                    ret = (ret + 1) % mod;
            }
        }
        return ret;
    }
    int reverse(int num) {
        int ret = 0;
        while (num) {
            ret = ret * 10 + num % 10;
            num /= 10;
        }
        return ret;
    }
};