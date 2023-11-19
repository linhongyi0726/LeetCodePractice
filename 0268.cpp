// First time
/*
    XOR
    a^b^b = a
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), ret = n;
        for (int i = 0; i < n; ++i) {
            ret ^= i;
            ret ^= nums[i];
        }
        return ret;
    }
};

/*
    Sum
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        return n * (n + 1) / 2 - accumulate(nums.begin(), nums.end(), 0);
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), ret = n;
        for (int i = 0; i < n; ++i) {
            ret += i - nums[i];
        }
        return ret;
    }
};

/*
    sort
    T: O(nlogn)/S: O(1)
    -----
    sort + binary search
    -> there won't be nums[m] < m case
    because there only contain n distinct numbers
        actual: 0 1 1 -> impassible!
        expect: 0 1 2
    T: O(nlogn)/S: O(1)
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (i != nums[i])
                return i;
        }
        return n;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), l = 0, r = n;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] > m)
                r = m;
            else if (nums[m] == m)
                l = m + 1;
        }
        return l;
    }
};