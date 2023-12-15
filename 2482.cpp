// First time
/*
    Two pass
    the row and col array denote the amount of 1,
    and the amount of 0 must be the row/column size - the amount of 1

    T: O(nm)/S: O(n+m)
*/
class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> row(n, 0), col(m, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                row[i] += grid[i][j];
                col[j] += grid[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                // grid[i][j] = row[i] - (n - row[i]) + col[j] - (m - col[j]);
                grid[i][j] = 2 * row[i] + 2 * col[j] - n - m;
            }
        }
        return grid;
    }
};

/*
    Three pass
    the row and col array denote the diff between the amount of 1 and 0

    T: O(nm)/S: O(n+m)
*/
class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), one = 0, zero = 0;
        vector<int> row(n, 0), col(m, 0);
        for (int i = 0; i < n; ++i) {
            one = 0;
            zero = 0;
            for (int j = 0; j < m; ++j) {
                if (grid[i][j])
                    one++;
                else
                    zero++;
            }
            row[i] = one - zero;
        }
        for (int j = 0; j < m; ++j) {
            one = 0;
            zero = 0;
            for (int i = 0; i < n; ++i) {
                if (grid[i][j])
                    one++;
                else
                    zero++;
            }
            col[j] = one - zero;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                grid[i][j] = row[i] + col[j];
            }
        }
        return grid;
    }
};