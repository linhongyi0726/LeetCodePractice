// First time
/*
    the same with problem 2905
    Optimization
    Just record the max and min of possible j (similar with the set approach)
    T: O(n)/S: O(1)
*/
class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n = nums.size(), mx = 0, mn = 0;
        for (int i = indexDifference; i < n; ++i) {
            // update the index of maximum and minimum of possible j
            if (nums[i - indexDifference] > nums[mx])
                mx = i - indexDifference;
            if (nums[i - indexDifference] < nums[mn])
                mn = i - indexDifference;
            if (nums[mx] - nums[i] >= valueDifference)
                return {i, mx};
            else if (nums[i] - nums[mn] >= valueDifference)
                return {i, mn};
        }
        return {-1, -1};
    }
};

/*
    the same with problem 2905
    Use map and binary search to find nums[i]+valueDifference or nums[i]-valueDifference
    T: O(nlogn)/S: O(n)
    -----
    Use set and choose the maximum and minimum possible j
    T: O(nlogn)/S: O(n)
*/
class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n = nums.size();
        map<int, int> mp;
        for (int i = indexDifference; i < n; ++i) {
            mp[nums[i - indexDifference]] = i - indexDifference;
            // find j which nums[j] >= nums[i] + valueDifference
            auto it = mp.lower_bound(nums[i] + valueDifference);
            if (it != mp.end())
                return {i, it->second};
            // find j which nums[j] <= nums[i] - valueDifference 
            it = mp.upper_bound(nums[i] - valueDifference);
            if (it != mp.begin())
                return {i, prev(it)->second};
        }
        return {-1, -1};
    }
};

class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n = nums.size();
        set<pair<int, int>> s;
        for (int i = indexDifference; i < n; ++i) {
            s.insert({nums[i - indexDifference], i - indexDifference});
            auto mn = s.begin();
            auto mx = s.rbegin();
            if (mx->first - nums[i] >= valueDifference)
                return {i, mx->second};
            else if (nums[i] - mn->first >= valueDifference)
                return {i, mn->second};
        }
        return {-1, -1};
    }
};

/*
    Brute-force (In problem 2905 will TLE)
    T: O(n^2)/S: O(1)
*/
class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + indexDifference; j < nums.size(); ++j) {
                if (abs(nums[i] - nums[j]) >= valueDifference)
                    return {i, j};
            }
        }
        return {-1, -1};
    }
};