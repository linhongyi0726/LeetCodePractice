// First time
/*
    Use diff array (or ordered map)
    *Notice the end time can be another meeting start time
    e.g. [[1,13], [13,15]] -> true

    T: O(nlogn)/S: O(n)
*/
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        map<int, int> diff;
        // [start, end) -> the end time no need to plus one (interval[1]+1)
        for (auto interval : intervals) {
            diff[interval[0]]++;
            diff[interval[1]]--;
        }
        int sum = 0;
        for (auto &it : diff) {
            sum += it.second;
            // it.second = sum;
            if (sum > 1)
                return false;
        }
        return true;
    }
};

/*
    T: O(nlogn)/S: O(1)
*/
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < intervals[i - 1][1])
                return false;
        }
        return true;
    }
};