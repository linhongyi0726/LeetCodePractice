// First time
/*
    Prefix sum + hash map (key: prefix sum, value: numbers of prefix sum)
    Use prefix sum i to find prefix sum j which diff is k
    [... j ... i]
        |_______|
            k
    *Notice mp[0]=1 to represent the array is empty,
    which can let us to count the sum of whole array
    T: O(n)/S: O(n)
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ret = 0, prefix = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (int& num : nums) {
            prefix += num;
            ret += mp[prefix - k];
            mp[prefix]++;
        }
        return ret;
    }
};