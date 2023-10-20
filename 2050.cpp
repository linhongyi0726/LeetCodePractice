// First time
/*
    Topological Sorting (BFS)
    Kahn's algorithm + DP
    traverse the graph and count the "maximum" month to finish the current course (a kind of DP)
    (because the maximum time can cover the shorter time, it will be more efficient)
    At last, find the maximum month
    -> it means the end point of the DAG (aka every courses are finished)

    T: O(V+E)/S: O(V+E)
*/
class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        // S: O(E)
        vector<vector<int>> graph(n + 1);
        // S: O(V)
        vector<int> indegree(n + 1), cost(n + 1);
        // T: O(E)
        for (int i = 0; i < relations.size(); ++i) {
            graph[relations[i][0]].push_back(relations[i][1]);
            indegree[relations[i][1]]++;
        }

        // T: O(V)
        queue<int> q;
        for (int i = 1; i <= n; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
                cost[i] = time[i - 1];
            }
        }
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int adj : graph[cur]) {
                indegree[adj]--;
                cost[adj] = max(cost[adj], cost[cur] + time[adj - 1]);
                if (indegree[adj] == 0)
                    q.push(adj);
            }
        }

        // find the end point
        int ret = 0;
        for (int month : cost)
            ret = max(ret, month);
        return ret;
    }
};