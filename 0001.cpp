// Second time
/*
    hash map (key: num, value: index)
    Do search and store at 1 pass
    *Note: Because solution is unique, num won't be duplicated -> can be key of map
    T: O(n)/S: O(n)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for (int i=0; i<nums.size(); ++i) {
            if (mp.count(target-nums[i]))
                return {mp[target-nums[i]], i};
            mp[nums[i]]=i;
        }
        return {};
    }
};


// First time
/*
    Use hash map
    key: number, value: index
    T: O(n)/S:(n)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for (int i = 0; i < nums.size(); ++i) {
            if (mp.find(target-nums[i]) != mp.end())
                return {mp[target-nums[i]], i};
            mp[nums[i]] = i;
        }
        return {};
    }
};