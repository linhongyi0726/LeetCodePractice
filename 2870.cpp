// First time
/*
    cnt = 3k
        -> k operations
    cnt = 3k + 1 = 3(k - 1) + 4
        -> k + 1 operations
    cnt = 3k + 2
        -> k + 1 operations

    T: O(n)/S: O(n)
*/
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ret = 0;
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }
        for (auto [num, cnt] : mp) {
            if (cnt == 1)
                return -1;
            ret += (cnt + 2) / 3;
        }
        return ret;
    }
};

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ret = 0;
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }
        for (auto [num, cnt] : mp) {
            if (cnt == 1)
                return -1;
            ret += cnt / 3;
            if (cnt % 3)
                ret++;
        }
        return ret;
    }
};

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ret = 0;
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }
        for (auto [num, cnt] : mp) {
            if (cnt % 3 == 0) {
                ret += cnt / 3;
                cnt = 0;
            } else if (cnt > 2 && (cnt - 2) % 3 == 0) {
                ret += (cnt - 2) / 3;
                cnt = 2;
            } else if (cnt > 4 && (cnt - 4) % 3 == 0) {
                ret += (cnt - 4) / 3;
                cnt = 4;
            }
            if (cnt % 2 == 0) {
                ret += cnt / 2;
            } else {
                return -1;
            }
        }
        return ret;
    }
};