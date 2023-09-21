// First time
/*
    Use sort without heap
    record the index at the end of row
    T: O(mlogm)/S: O(1)
*/
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        for (int i = 0; i < mat.size(); ++i)
            mat[i].push_back(i);
        sort(mat.begin(), mat.end());
        vector<int> ret(k, 0);
        for (int i = 0; i < k; ++i)
            ret[i] = mat[i].back();
        return ret;
    }
};

/*
    Use max heap to store the k-th weak rows
    T: O(mn)/S: O(k)
    -----
    Use binary search to count the soldiers number
    T: O(mlogn)/S: O(k)
*/
class Solution {
public:
    int BS(vector<int> &row) {
        int l = 0, r = row.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (row[m] == 0)
                r = m -1;
            else if (row[m] == 1)
                l = m + 1;
        }
        return l;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>> pq;
        int m = mat.size(), n = mat[0].size();
        for (int i = 0; i < m; ++i) {
            pq.push(make_pair(BS(mat[i]), i));
            if (pq.size() > k)
                pq.pop();
        }
        vector<int> ret(k, 0);
        while (!pq.empty() && k > 0) {
            ret[--k] = pq.top().second;
            pq.pop();
        }
        return ret;
    }
};

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>> pq;
        int m = mat.size(), n = mat[0].size();
        for (int i = 0; i < m; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1)
                    cnt++;
                else
                    break;
            }
            pq.push(make_pair(cnt, i));
            if (pq.size() > k)
                pq.pop();
        }
        vector<int> ret(k, 0);
        while (!pq.empty() && k > 0) {
            ret[--k] = pq.top().second;
            pq.pop();
        }
        return ret;
    }
};