// First time
/*
    Use hash map to record count and calculate the sum (1+2+...+(cnt-1))
    T: O(n^2)/S: O(n)
    -----
    use formula or optimize in one loop to count and accumulate
    T: O(n)/S: O(n)
*/
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ret = 0;
        for (int num : nums) {
            ret += mp[num];
            mp[num]++;
        }
        return ret;
    }
};

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ret = 0;
        for (int num : nums)
            mp[num]++;
        for (auto &[num, cnt] : mp) {
            // ret += (1 + (cnt - 1)) * (cnt - 1) / 2;
            for (int i = 1; i < cnt; ++i)
                ret += i;
        }
        return ret;
    }
};