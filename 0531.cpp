// First time
/*
    The same with problem 1582
    T: O(nm)/S: O(n+m)
*/
class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int n = picture.size(), m = picture[0].size(), ret = 0;
        vector<int> row(n, 0), col(m, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (picture[i][j] == 'B') {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (picture[i][j] == 'B' && row[i] == 1 && col[j] == 1)
                    ret++;
            }
        }
        return ret;
    }
};