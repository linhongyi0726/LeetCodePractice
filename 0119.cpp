// Second time
/*
    Create the result array witch size is for rowIndex
    Because we only need the top and left-top number to add for current number,
    we can iterate from the end to avoid overriding the previous row answer
    T: O(n^2)/S: O(n)
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> dp(rowIndex + 1, 1);
        for (int row = 2; row <= rowIndex; ++row) {
            for (int col = row - 1; col >= 1; --col) {
                dp[col] = dp[col - 1] + dp[col];
            }
        }
        return dp;
    }
};

/*
    construct the Pascal's Triangle
    T: O(n^2)/S: O(n^2)
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> dp;
        for (int row = 0; row <= rowIndex; ++row) {
            vector<int> cur(row + 1, 1);
            for (int col = 1; col < row; ++col) {
                cur[col] = dp[row - 1][col - 1] + dp[row - 1][col];
            }
            dp.push_back(cur);
        }
        return dp[rowIndex];
    }
};


// First time
/*
       1
      1 1
     1 2 1
    1 3 3 1
       V
    1 1 1 1
    1 1 1 1
    1 2 1 1
    1 3 3 1

    T: O(n^2)/S: O(n)
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret(rowIndex + 1, 1);
        // for (int row = 2; row <= rowIndex; ++row) {
        for (int row = 0; row <= rowIndex; ++row) {
            int prev = ret[0];
            for (int col = 1; col < row; ++col) {
                int tmp = ret[col];
                ret[col] += prev;
                prev = tmp;
            }
        }
        return ret;
    }
};

/*
    From problem 118 -> create whole Pascal's Triangle
    T: O(n^2)/S: O(n^2)
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ret;
        for (int i = 0; i < rowIndex + 1; ++i) {
            vector<int> cur(i + 1, 1);
            for (int j = 1; j < i; ++j) {
                cur[j] = ret[i - 1][j - 1] + ret[i - 1][j];
            }
            ret.push_back(cur);
        }
        return ret[rowIndex];
    }
};