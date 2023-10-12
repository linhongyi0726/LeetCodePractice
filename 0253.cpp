// First time
/*
    heap
    Use min-heap to get the recently finished meeting
    If the next meeting start time is after recently finished time
    -> There is a meeting room be released
    The max meeting rooms is the max of heap size

    T: O(nlogn)/S: O(n)
*/
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        int ret = 0;
        for (auto interval : intervals) {
            // meeting end
            while (!pq.empty() && pq.top() <= interval[0])
                pq.pop();
            // new meeting
            pq.push(interval[1]);
            int n = pq.size();
            ret = max(ret, n);
        }
        return ret;
    }
};

/*
    sweep line (diff array) + map
    T: O(nlogn)/S: O(n)
*/
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> diff;
        for (auto interval : intervals) {
            diff[interval[0]]++;
            diff[interval[1]]--;
        }
        int sum = 0, ret = 0;
        for (auto &it : diff) {
            sum += it.second;
            ret = max(ret, sum);
        }
        return ret;
    }
};