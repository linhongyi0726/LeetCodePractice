// First time
/*
    There is must only one champion -> only one node indegree is 0
    T: O(n)/S: O(n)
*/
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        int num;
        for (auto e : edges) {
            indegree[e[1]]++;
        }
        int ret = -1;
        for (int i = 0; i < n; ++i) {
            if (!indegree[i]) {
                if (ret == -1)
                    ret = i;
                else
                    return -1;
            }
        }
        return ret;
    }
};