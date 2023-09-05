// First time
/*
    prefix sum + hash map (key: modulo of prefix sum, value: numbers of prefix sum)

    [... j ... i]
        |_______|
          [j:i] = prefix[0:i] - prefix[0:j-1]
    If prefix[0:j] and prefix[0:i] have the same remainder of k
    -> [j:i] can be divisible by k
    So it means we only need to find the same modulo, then accumulate its count

    Before we store in map, we should calculate its remainder
    *Notice to avoid the negative number, we should do sum % k + k first
    (Let original modulo add k before we get modulo of k)

    T: O(n)/S: O(n)
*/
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0, ret = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            int mod = (sum % k + k) % k;
            ret += mp[mod];
            mp[mod]++;
        }
        return ret;
    }
};

// Optimize
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int prefix = 0, ret = 0;
        for (int i = 0; i < nums.size(); ++i) {
            prefix = (prefix + nums[i] % k + k) % k;
            ret += mp[prefix];
            mp[prefix]++;
        }
        return ret;
    }
};