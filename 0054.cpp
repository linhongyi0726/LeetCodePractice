// First time
/*
    similar as problem 59
     -------- < u
    |       |
    |       |
    -------- < d
    ^       ^
    l       r
    T: O(n^2)/S: O(1)
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int l=0, r=matrix[0].size()-1, u=0, d=matrix.size()-1;
        int row=u, col=l, dir=0;
        while (l<=r && u<=d) {
            ans.push_back(matrix[row][col]);
            switch (dir) {
                case 0:
                    if (col < r) col++;
                    else {dir=1; row=++u;}
                    break;
                case 1:
                    if (row < d) row++;
                    else {dir=2; col=--r;}
                    break;
                case 2:
                    if (col > l) col--;
                    else {dir=3; row=--d;}
                    break;
                case 3:
                    if (row > u) row--;
                    else {dir=0; col=++l;}
                    break;
                default:
                    break;
            }
        }
        return ans;
    }
};

/*
    Add if judgement to avoid the matrix is rectangle
    T: O(n^2)/S: O(1)
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int l=0, r=matrix[0].size()-1, u=0, d=matrix.size()-1;
        int row=u, col=l;
        while (l<=r && u<=d) {
            for (col=l; col<=r; ++col) ans.push_back(matrix[u][col]);
            if (++u > d) break;

            for (row=u; row<=d; ++row) ans.push_back(matrix[row][r]);
            if (--r < l) break;

            for (col=r; col>=l; --col) ans.push_back(matrix[d][col]);
            if (--d < u) break;

            for (row=d; row>=u; --row) ans.push_back(matrix[row][l]);
            if (++l > r) break;
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int l=0, r=matrix[0].size()-1, u=0, d=matrix.size()-1;
        int row=u, col=l;
        while (l<=r && u<=d) {
            row=u; col=l;
            while (col<=r) ans.push_back(matrix[row][col++]);
            if (++u > d) break;

            row=u; col=r;
            while (row<=d) ans.push_back(matrix[row++][col]);
            if (--r < l) break;

            row=d; col=r;
            while (col>=l) ans.push_back(matrix[row][col--]);
            if (--d < u) break;

            row=d; col=l;
            while (row>=u) ans.push_back(matrix[row--][col]);
            if (++l > r) break;
        }
        return ans;
    }
};