// First time
/*
    Without the extra space, just modify the original matrix to record the height of 1
    [[0, 0, 1],    [[0, 0, 1],
     [1, 1, 1], ->  [1, 1, 2],
     [1, 0, 1]]     [2, 0, 3]]

    T: O(n*mlogm)/S: O(1)
*/
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int y = matrix.size(), x = matrix[0].size(), ret = 0;
        for (int row = 0; row < y; ++row) {
            for (int col = 0; col < x; ++col) {
                if (matrix[row][col] == 1 && row > 0)
                    matrix[row][col] = matrix[row - 1][col] + 1;
            }
            vector<int> tmp = matrix[row];
            sort(tmp.begin(), tmp.end());
            for (int i = 0; i < x; ++i) {
                ret = max(ret, tmp[i] * (x - i));
            }
        }
        return ret;
    }
};

/*
    Calculate the height of 1 at each matrix[row][col]
      matrix        height
    [[0, 0, 1], -> [0, 0, 1] -> ret: 1
     [1, 1, 1], -> [1, 1, 2] -> ret: 2 (2*1)
     [1, 0, 1]] -> [2, 0, 3] -> ret: 4 (2*2), and it's greater than 3*1

    T: O(n*mlogm)/S: O(m)
*/
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int y = matrix.size(), x = matrix[0].size(), ret = 0;
        vector<int> height(x, 0);
        for (int row = 0; row < y; ++row) {
            for (int col = 0; col < x; ++col) {
                if (matrix[row][col] == 1)
                    height[col]++;
                else
                    height[col] = 0;
            }
            vector<int> tmp = height;
            sort(tmp.begin(), tmp.end());
            for (int i = 0; i < x; ++i) {
                ret = max(ret, tmp[i] * (x - i));
            }
        }
        return ret;
    }
};