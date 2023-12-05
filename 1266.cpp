// First time
/*
    calculate the diff of x and y distance between two points
    If we move diagonally, we can move nearly at both x and y,
    So we can move diagonally first (mx), then plus the remain path (mx-mn)
    -> Actually the minimum move path is the max diff of x and y
    e.g. (1,1) -> (3,4)
        move 3 path (diff of y direction)
    
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ret = 0;
        for (int i = 1; i < points.size(); ++i) {
            int xdiff = abs(points[i][0] - points[i - 1][0]);
            int ydiff = abs(points[i][1] - points[i - 1][1]);
            int mx = max(xdiff, ydiff), mn = min(xdiff, ydiff);
            ret += mn + (mx - mn);
        }
        return ret;
    }
};

// optimize
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ret = 0;
        for (int i = 1; i < points.size(); ++i) {
            int xdiff = abs(points[i][0] - points[i - 1][0]);
            int ydiff = abs(points[i][1] - points[i - 1][1]);
            ret += max(xdiff, ydiff);
        }
        return ret;
    }
};