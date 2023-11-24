// First time
/*
    BFS
       0 1 2
      ------
    0 |x y z
    1 |y z
    2 |z
       ^
       in column 0, we need to push the under number and the right number into the queue
       in other columns, we just need to push the right number into the queue

    T: O(n)/S: O(n)
*/
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> ret;
        queue<pair<int, int>> q;
        q.push({0, 0});
        while (!q.empty()) {
            int row = q.front().first, col = q.front().second;
            q.pop();
            ret.push_back(nums[row][col]);
            if (col == 0 && row + 1 < nums.size())
                q.push({row + 1, col});
            if (col + 1 < nums[row].size())
                q.push({row, col + 1});
        }
        return ret;
    }
};

/*
    We can use i+j to group the output array, every slash has the same value (i+j)
       0 1 2 3
      --------
    0 |0 1 2 3
    1 |1 2 3 4
    2 |2 3 4 5
    3 |3 4 5 6
    
    Use hash map to group them, and put into the map from the end of 2-D array,
    thus the order will be the same with we want
    *Notice to compute the max key, so that we can traverse from 0 to max key value,

    T: O(n)/S: O(n)
*/
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> ret;
        unordered_map<int, vector<int>> mp;
        int mxkey = 0;
        for (int i = nums.size() - 1; i >= 0; --i) {
            for (int j = nums[i].size() - 1; j >= 0; --j) {
                mp[i + j].push_back(nums[i][j]);
                mxkey = max(mxkey, i + j);
            }
        }
        for (int i = 0; i <= mxkey; ++i) {
            for (int j : mp[i]) {
                ret.push_back(j);
            }
        }
        return ret;
    }
};

/*
    Use map or heap to keep the order of i+j

    T: O(nlogn)/S: O(n)
*/
// Use map
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> ret;
        map<int, vector<int>> mp;
        for (int i = nums.size() - 1; i >= 0; --i) {
            for (int j = nums[i].size() - 1; j >= 0; --j) {
                mp[i + j].push_back(nums[i][j]);
            }
        }
        for (auto it : mp) {
            for (int i : it.second) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};

// Use heap
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> ret;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = nums.size() - 1; i >= 0; --i) {
            for (int j = nums[i].size() - 1; j >= 0; --j) {
                pq.push({i + j, j});
            }
        }
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            ret.push_back(nums[cur.first - cur.second][cur.second]);
        }
        return ret;
    }
};