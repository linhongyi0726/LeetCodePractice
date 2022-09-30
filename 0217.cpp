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