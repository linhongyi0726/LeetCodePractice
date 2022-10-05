// First time
/*
    Use BFS
    Store every 0 into queue to be a BFS start point, then change every 1 to -1 for BFS convenience
    BFS for every elements and update distance if the element is -1 (distance always > 0)
    m = mat.size()
    n = mat[0].size()
    T: O(mn)/S: O(mn)
*/
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int, int>> q;
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < mat.size(); ++i) {
            for (int j = 0; j < mat[0].size(); ++j) {
                if (mat[i][j] == 0)
                    q.push({i, j});
                else
                    mat[i][j] = -1;
            }
        }
        while (!q.empty()) {
            auto p = q.front(); q.pop();
            for (auto dir : dirs) {
                int x = p.first + dir.first;
                int y = p.second + dir.second;
                if (x >= 0 && x < mat.size() && y >= 0 && y < mat[0].size() && mat[x][y] == -1) {
                        mat[x][y] = mat[p.first][p.second]+1;
                        q.push({x, y});
                }
            }
        }
        return mat;
    }
};