// First time
/*
    [1, 2,|3] < rowstart
    ------|
    [8,|9,|4]
       |-----
    [7,|6, 5] < rowend
     ^     ^
 colstart colend

    keep the boundary [left, right)
    -> will leave the middle if n is odd

    T: O(n^2)/S: O(1)
*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector(n, 0));
        int rowstart=0, colstart=0, rowend=n-1, colend=n-1, cur=1;
        while (rowstart<=rowend && colstart<=colend) {
            // one while loop means one layer of matrix
            int row=rowstart, col=colstart;
            // right: move col
            while (col < colend) ans[rowstart][col++]=cur++;
            // down: move row
            while (row < rowend) ans[row++][colend]=cur++;
            // left: move col
            while (col > colstart) ans[rowend][col--]=cur++;
            // up: move row
            while (row > rowstart) ans[row--][colstart]=cur++;
            rowstart++; colstart++;
            rowend--; colend--;
        }
        if (n%2) ans[rowstart-1][colstart-1]=cur;
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector(n, 0));
        int rowstart=0, colstart=0, rowend=n-1, colend=n-1, cur=1;
        while (rowstart<=rowend && colstart<=colend) {
            for (int r=colstart; r<colend; ++r) ans[rowstart][r]=cur++;
            for (int d=rowstart; d<rowend; ++d) ans[d][colend]=cur++;
            for (int l=colend; l>colstart; --l) ans[rowend][l]=cur++;
            for (int u=rowend; u>rowstart; --u) ans[u][colstart]=cur++;
            rowstart++; colstart++;
            rowend--; colend--;
        }
        if (n%2) ans[rowstart-1][colstart-1]=cur;
        return ans;
    }
};

/*
    [1, 2, 3]
    ---------
    [8,|9,|4]
    ------|
    [7, 6,|5]
    The boundary will be dynamic in four direction,

    T: O(n^2)/S: O(1)
*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector(n, 0));
        int rowstart=0, colstart=0, rowend=n-1, colend=n-1, cur=1;
        int row=0, col=0, dir=0;
        while (rowstart<=rowend && colstart<=colend) {
            ans[row][col]=cur++;
            switch (dir) {
                case 0: // right
                    if (col < colend) col++;
                    else {dir=1; row=++rowstart;}
                    break;
                case 1: // down
                    if (row < rowend) row++;
                    else {dir=2; col=--colend;}
                    break;
                case 2: //left
                    if (col > colstart) col--;
                    else {dir=3; row=--rowend;}
                    break;
                case 3: //up
                    if (row > rowstart) row--;
                    else {dir=0; col=++colstart;}
                    break;
                default:
                    break;
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector(n, 0));
        int rowstart=0, colstart=0, rowend=n-1, colend=n-1, cur=1;
        while (rowstart<=rowend && colstart<=colend) {
            for (int r=colstart; r<=colend; ++r) ans[rowstart][r]=cur++;
            rowstart++;
            for (int d=rowstart; d<=rowend; ++d) ans[d][colend]=cur++;
            colend--;
            for (int l=colend; l>=colstart; --l) ans[rowend][l]=cur++;
            rowend--;
            for (int u=rowend; u>=rowstart; --u) ans[u][colstart]=cur++;
            colstart++;
        }
        return ans;
    }
};