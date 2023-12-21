// First time
/*
    Only consider x-coordinates
    T: O(nlogn)/S: O(n)
*/
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int ret = 0;
        vector<int> x;
        for (auto point : points)
            x.push_back(point[0]);
        sort(x.begin(), x.end());
        for (int i = 1; i < x.size(); ++i) {
            ret = max(ret, x[i] - x[i - 1]);
        }
        return ret;
    }
};

/*
    T: O(nlogn)/S: O(1)
*/
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int ret = 0;
        for (int i = 1; i < points.size(); ++i) {
            ret = max(ret, points[i][0] - points[i - 1][0]);
        }
        return ret;
    }
};