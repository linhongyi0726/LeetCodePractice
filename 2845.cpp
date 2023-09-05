// First time
/*
    prefix sum + hash map

    There are two requirements
    1. nums[i] % modulo == k
        Change elements of array to 1 or 0 by (% modulo == k) or not
        -> Reduce to problem 974: find the sub-array which sum's modulo is k
    2. cnt % modulo == k
        cnt: the count of numbers that satisfied requirement 1
        We can use prefix sum to count the cnt (because the array have be filled 1 and 0 already)
        *Notice mp[0]=1, it represent the array is empty (prefix sum is zero),
        It also can let us calculate the whole array sum by prefix[0:n] - prefix[0:0]

    Find the prefix sum that has the same modulo of k to count the sub-array
    If [j:i] is interesting sub-array, prefix[0:j-1] and prefix[0:i] must have the same modulo of k
    ex. % 3 == 1
    [... j ... i]
    |___|_______|
      1     4
    modulo of prefix[0:i]: (5 - 1) % 3 = 1
    modulo of prefix[0:j-1]: 1 % 3 = 1

    To avoid negative number, we can add modulo before we get the modulo of k,
    or we can only use sum - k to make sure no negative number

    T: O(n)/S: O(n)
*/
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long ret = 0, sum = 0, mod = 0;
        for (int& num : nums) {
            num = (num % modulo == k);
        }
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (int num : nums) {
            sum += num;
            mod = sum % modulo;
            ret += mp[(mod - k + modulo) % modulo];
            // ret += mp[(sum - k) % modulo];
            mp[mod]++;
        }
        return ret;
    }
};

// Use one variable to record the prefix sum and its' mod
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long ret = 0, prefix = 0;
        for (int& num : nums) {
            num = (num % modulo == k);
        }
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (int& num : nums) {
            prefix = (prefix + num) % modulo;
            ret += mp[(prefix - k + modulo) % modulo];
            mp[prefix]++;
        }
        return ret;
    }
};

// neat code
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long ret = 0, prefix = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (int& num : nums) {
            prefix = (prefix + (num % modulo == k)) % modulo;
            ret += mp[(prefix - k + modulo) % modulo];
            mp[prefix]++;
        }
        return ret;
    }
};