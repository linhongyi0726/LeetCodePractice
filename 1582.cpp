// First time
/*
    The same with problem 531
    T: O(nm)/S: O(n+m)
*/
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(), ret = 0;
        vector<int> row(n, 0), col(m, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 1) {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 1 && row[i] == 1 && col[j] == 1)
                    ret++;
            }
        }
        return ret;
    }
};

/*
    First find the only 1 at row, then check its column has other 1 or not
    T: O(n*(m+n))/S: O(n+m)
*/
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(), ret = 0;
        for (int i = 0; i < n; ++i) {
            int j = 0, idx = -1;
            for (; j < m; ++j) {
                if (mat[i][j] == 1) {
                    if (idx != -1)
                        break;
                    else
                        idx = j;
                }
            }
            if (j == m && idx != -1) {
                int sum = 0;
                for (int k = 0; k < n; ++k) {
                    sum += mat[k][idx];
                }
                if (sum == 1)
                    ret++;
                /*
                int k = 0;
                for (; k < n; ++k) {
                    if (mat[k][idx] == 1 && k != i)
                        break;
                }
                if (k == n)
                    ret++;
                */
            }
        }
        return ret;
    }
};