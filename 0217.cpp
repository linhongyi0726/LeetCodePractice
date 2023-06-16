// Second time
/*
    BTW unordered_set is also implemented by hash table
    T: O(n)/S: O(n)
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int num : nums) {
            if (mp.count(num)) return true;
            mp[num]++;
        }
        return false;
    }
};

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (int num : nums) {
            if (s.count(num)) return true;
            s.insert(num);
        }
        return false;
    }
};

/*
    T: O(nlogn)/S: O(1)
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size(); ++i) {
            if (i!=nums.size()-1 && nums[i]==nums[i+1]) return true;
        }
        return false;
    }
};

// First time
/*
    1. Use hash map or set
        T: O(n)/S: (n)
    2. Sort and compare nearby two element
        T: O(nlogn)/S: O(1)
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (int num : nums) {
            if (s.count(num))
                return true;
            s.insert(num);
        }
        return false;
    }
};

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return nums.size() > set(nums.begin(), nums.end()).size();
    }
};