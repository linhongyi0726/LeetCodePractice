// First time
/*
    BFS by queue
    store all rotten oranges at queue first, then rot other fresh oranges by 4 directions
    T: O(mn)/S: O(mn)
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0, m = grid.size(), n = grid[0].size(), fresh = 0;
        queue<pair<int,int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0 ; j < n; ++j) {
                if (grid[i][j] == 1) ++fresh;
                else if (grid[i][j] == 2) q.push({i,j});
            }
        }
        vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        while (!q.empty() && fresh) {
            // Notice we should store the size of queue first
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                auto cur = q.front(); q.pop();
                for (auto dir : dirs) {
                    if (cur.first + dir.first >= 0 && cur.first + dir.first < m
                        && cur.second + dir.second >= 0 && cur.second + dir.second < n
                        && grid[cur.first + dir.first][cur.second + dir.second] == 1) {
                            grid[cur.first + dir.first][cur.second + dir.second] = 2;
                            q.push({cur.first + dir.first, cur.second + dir.second});
                            --fresh;
                        }
                }
            }
            ++ans;
        }
        return fresh == 0 ? ans : -1;
    }
};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0, m = grid.size(), n = grid[0].size(), fresh = 0;
        queue<pair<int,int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0 ; j < n; ++j) {
                if (grid[i][j] == 1) ++fresh;
                else if (grid[i][j] == 2) q.push({i,j});
            }
        }
        while (!q.empty() && fresh) {
            // Notice we should store the size of queue first
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                auto cur = q.front(); q.pop();
                if (cur.first+1 < m && grid[cur.first+1][cur.second] == 1) {
                    grid[cur.first+1][cur.second] = 2;
                    --fresh;
                    q.push({cur.first+1, cur.second});
                }
                if (cur.first-1 >= 0 && grid[cur.first-1][cur.second] == 1) {
                    grid[cur.first-1][cur.second] = 2;
                    --fresh;
                    q.push({cur.first-1, cur.second});
                }
                if (cur.second+1 < n && grid[cur.first][cur.second+1] == 1) {
                    grid[cur.first][cur.second+1] = 2;
                    --fresh;
                    q.push({cur.first, cur.second+1});
                }
                if (cur.second-1 >= 0 && grid[cur.first][cur.second-1] == 1) {
                    grid[cur.first][cur.second-1] = 2;
                    --fresh;
                    q.push({cur.first, cur.second-1});
                }
            }
            ++ans;
        }
        return fresh == 0 ? ans : -1;
    }
};