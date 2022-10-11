// First time
/*
    Topological Sort
    Only Directed Acyclic Graph (DAG) can be topological sorted, can not have cycle

    Use Adjacency List to store the graph, and one vector to store unvisited, visiting or visited
    (Or can use two vector "todo" and "done")
    Check is cyclic or not by DFS, BTW the topological ordering will be the reverse of the result
    T: O(V+E)/ S: O(V+E)
*/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjlist(numCourses, vector<int>{});
        vector<int> visited(numCourses, 0);
        for (auto prerequisite : prerequisites)
            adjlist[prerequisite[1]].push_back(prerequisite[0]);
        for (int i = 0; i < adjlist.size(); ++i)
            if (dfs(adjlist, visited, i)) return false;
        return true;
    }
    // Check have cycle or not
    // 0: unvisited, 1: visiting, 2: visited
    bool dfs(vector<vector<int>> &adjlist, vector<int> &visited, int node) {
        if (visited[node] == 1) return true;        // cyclic
        else if (visited[node] == 2) return false;  // visited
        else {
            visited[node] = 1;
            for (auto adj : adjlist[node]) {
                if (dfs(adjlist, visited, adj)) return true;
            }
            visited[node] = 2;
        }
        return false;
    }
};

/*
    BFS
    If degree[i] == 0, means there aren't any edges connect to the node, so it can be a start point to BFS
    Choose one start point and remove all edges connected to it (subtract one of adjacent point's degree)
    If there is no cycle, all points will be pushed to the queue one time, here numCourses will become zero
    T: O(V+E)/ S: O(V+E)
*/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjlist(numCourses, vector<int>{});
        vector<int> degree(numCourses, 0);
        queue<int> q;
        for (auto prerequisite : prerequisites) {
            adjlist[prerequisite[1]].push_back(prerequisite[0]);
            ++degree[prerequisite[0]];
        }
        for (int i = 0; i < degree.size(); ++i) {
            if (!degree[i]) {
                q.push(i);
                --numCourses;
            }
        }
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (auto adj : adjlist[cur]) {
                --degree[adj];
                if (!degree[adj]) {
                    q.push(adj);
                    --numCourses;
                }
            }
        }
        return numCourses == 0;
    }
};