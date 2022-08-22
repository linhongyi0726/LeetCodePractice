// First time
/*
    Brute-force
    T: O(n^3)/S: O(1)
*/
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int ret = 0;
        for (int i = 0; i < nums.size() - 2; i++) {
            for (int j = i + 1; j < nums.size() - 1; j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    if ((nums[j] - nums[i] == diff) && (nums[k] - nums[j] == diff))
                        ret++;
                }
            }
        }
        return ret;
    }
};

/*
    Use map
    T: O(n)/S: O(n)
*/
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int ret = 0;
        unordered_map<int,bool> mp;
        for (int i = 0; i < nums.size(); i++)
            mp[nums[i]] = true;
        for (int i = 0; i < nums.size(); i++) {
            if (mp[nums[i] + diff] && mp[nums[i] + 2*diff])
                ret++;
        }
        return ret;
    }
};


/*
    Use set
    T: O(n)/S: O(n)
*/
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int ret = 0;
        set<int> set;
        for (int i = 0; i < nums.size(); i++) {
            if ((set.find(nums[i] - diff) != set.end()) && (set.find(nums[i] - 2*diff) != set.end()))
                ret++;
            set.insert(nums[i]);
        }
        return ret;
    }
};