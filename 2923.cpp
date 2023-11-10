// First time
/*
    Check when i != j, all grid[i][j] = 1 -> return i
    T: O(n^2)/S: O(1)
    -----
    Sum all grid[i], if the result == n-1 means it only lose itself
    T: O(n^2)/S: O(1)
*/
class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n; ++i) {
            int sum = accumulate(grid[i].begin(), grid[i].end(), 0);
            if (sum == n - 1)
                return i;
        }
        return 0;
    }
};

/*
    Simply refresh the champion when we find the stranger one
    T: O(n)/S: O(1)
*/
class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size(), cham = 0;
        for (int i = 1; i < n; ++i) {
            if (grid[i][cham] == 1)
                cham = i;
        }
        return cham;
    }
};