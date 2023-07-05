// First time
/*
    BFS
    similar with problem 994
    T: O(mn)/S: O(mn)
*/
class Solution {
public:
    int minKnightMoves(int x, int y) {
        vector<pair<int, int>> dirs = {
            {1, 2}, {2, 1}, {1, -2}, {2, -1},
            {-1, -2}, {-2, -1}, {-1, 2}, {-2, 1}
        };
        unordered_set<string> visited;
        queue<pair<int, int>> q;
        int ans = 0;
        x = abs(x); y = abs(y);
        visited.insert("0,0");
        q.push({0,0});
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto cur = q.front(); q.pop();
                if (cur.first == x && cur.second == y) return ans;
                for (auto dir : dirs) {
                    if (!visited.count(to_string(cur.first + dir.first)+','+to_string(cur.second + dir.second))
                        && cur.first + dir.first >= -1 && cur.first + dir.first <= x + 2
                        && cur.second + dir.second >= -1 && cur.second + dir.second <= y + 2) {
                            q.push({cur.first + dir.first, cur.second + dir.second});
                            visited.insert(to_string(cur.first + dir.first)+','+to_string(cur.second + dir.second));
                        }
                }
            }
            ++ans;
        }
        return ans;
    }
};

/*
    DFS
*/