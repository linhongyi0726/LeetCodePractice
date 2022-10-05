// First time
/*
    There are three cases
    1. intervals[i] is before newInterval
        -> push_back intervals[i] then move on
    2. intervals[i] is after newInterval
        -> push_back newInterval and other remain intervals[i]
    3. newInterval is overlap with intervals[i]
        -> Merge intervals[i] to the newInterval
    T: O(n)/S: O(n)
    ---
    *Try to use insert and erase to reduce space complexity?
    when overlapping, merge to newInterval then insert it and erase already merged intervals[i]s
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        for (int i = 0; i < intervals.size(); ++i) {
            if (intervals[i][1] < newInterval[0])
                ans.push_back(intervals[i]);
            else if (newInterval[1] < intervals[i][0]) {
                ans.push_back(newInterval);
                while (i < intervals.size())
                    ans.push_back(intervals[i++]);
                return ans;
            }
            else // newInterval[0] <= intervals[i][1] || newInterval[1] >= intervals[i][0]
                newInterval = {min(newInterval[0], intervals[i][0]), max(newInterval[1], intervals[i][1])};
        }
        ans.push_back(newInterval);
        return ans;
    }
};