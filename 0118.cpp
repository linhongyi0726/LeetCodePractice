// First time
/*
    i=0   1
    i=1  1 1
    i=2 1 2 1
          ^
         j=1 -> cur[j] = ret[i-1][j-1] + ret[i-1][j]

    T: O(n^2)/S: O(n^2)
*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        for (int i = 0; i < numRows; ++i) {
            vector<int> cur(i + 1, 1);
            for (int j = 1; j < i; ++j) {
                cur[j] = ret[i - 1][j - 1] + ret[i - 1][j];
            }
            ret.push_back(cur);
        }
        return ret;
    }
};

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        for (int i = 1; i <= numRows; ++i)
            ret.push_back(vector(i, 1));
        for (int i = 2; i < numRows; ++i) {
            for (int j = 1; j < i; ++j) {
                ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
            }
        }
        return ret;
    }
};