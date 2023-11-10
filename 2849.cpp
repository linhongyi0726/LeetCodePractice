// First time
/*
    Because We can walk slanted (if we walk slanted, we can reach x and y direction simultaneously)
    -> the minimum times is max(abs(sx-fx), abs(sy-fy)) (also can be min(x, y) + abs(x-y))
    If we can reach the end point <= t times, we must can reach it at actually t times
    we just need to stay around its adjacent cells for awhile

    Notice to handle the start point = end point case, and the t can't be 1,
    because we can go back to end point

    T: O(1)/S: O(1)
*/
class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int mn = max(abs(sx - fx), abs(sy - fy));
        if (mn == 0)
            return t != 1;
        else
            return t >= mn;
    }
};

/*
    BFS -> MLE
*/
class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if (sx == fx && sy == fy)
            return t != 1;
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        queue<pair<int, int>> q;
        q.push({sx, sy});
        int times = 0, lb = min(sx, fx), rb = max(sx, fx), ub = max(sy, fy), db = min(sy, fy);
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                auto cur = q.front();
                q.pop();
                if (times > t)
                    return false;
                if (cur.first == fx && cur.second == fy && times <= t)
                    return true;
                for (int i = 0; i < 8; ++i) {
                    int x = cur.first + dir[i].first;
                    int y = cur.second + dir[i].second;
                    if (x >= lb && x <= rb && y >= db && y <= ub)
                        q.push({x, y});
                }
            }
            times++;
        }
        return false;
    }
};