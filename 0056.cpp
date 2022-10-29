// First time
/*
    if intervals[i] overlap with ans.back(), merge it
    T: O(nlogn)/S: O(n)
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            if (ans.back()[1] >= intervals[i][0])
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            else
                ans.push_back(intervals[i]);
        }
        return ans;
    }
};

/*
    Use 2 ptr to check intervals[i] and intervals[i+1] overlap or not
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int l = 0, r;
        sort(intervals.begin(), intervals.end());
        while (l < intervals.size()) {
            r = l+1;
            while (r < intervals.size() && intervals[l][1] >= intervals[r][0])
                intervals[l][1] = max(intervals[l][1], intervals[r++][1]);
            ans.push_back(intervals[l]);
            l = r;
        }
        return ans;
    }
};