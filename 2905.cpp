// First time
/*
    Optimization
    Just need to record the max and min of possible j (similar with the set approach)
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
    if the answer pair is {j, i} which j <= i
    Use map to record possible {nums[j], j}

    idxdiff           idxdiff
    |-----|-----------|-----|
    j     i ->______________|
    |_________________|
      mp: {nums[j], j}

    In every loop, the number in the map which index must <= i-indexDifference
    So we don't need to check the index,
    just binary search to find the nums[j] which is larger/smaller than nums[i]+-valueDifference

      valdiff   valdiff
    |---------|---------|
    |^     nums[i]      ^
    |upper_bound     lower_bound -> possible answer
    ^
    prev(it) -> possible answer

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

// the same idea by using set
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
    Use map to record {number, array of each index},
    then binary search to find the smallest possible answer, and check it's index
    If not, move to next possible answer
    T: O(nlogn*m)/S: O(n)
*/
class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n = nums.size();
        map<int, vector<int>> mp;
        for (int i = 0; i < n; ++i)
            mp[nums[i]].push_back(i);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            auto it = mp.lower_bound(nums[i] + valueDifference);
            while (it != mp.end()) {
                for (int j = 0; j < mp[nums[i]].size(); ++j) {
                    for (int k = 0; k < it->second.size(); ++k) {
                        if (abs(mp[nums[i]][j] - it->second[k]) >= indexDifference)
                            return {mp[nums[i]][j], it->second[k]};
                    }
                }
                it = next(it);
            }
        }
        return {-1, -1};
    }
};