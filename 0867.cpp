// First time
/*
    T: O(nm)/S: O(nm)
*/
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> ret(m, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ret[j][i] = matrix[i][j];
            }
        }
        return ret;
    }
};