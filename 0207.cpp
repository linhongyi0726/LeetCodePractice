// Second time
/*
    Make a DAG and dfs check every node has cycle or not
    T: O(V+E)/S: O(V+E)
*/
class Solution {
private:
    const int unvisted = 0, visting = 1, visted = 2;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> status(numCourses, unvisted);
        for (auto v : prerequisites) {
            graph[v[1]].push_back(v[0]);
        }
        for (int i = 0; i < numCourses; ++i) {
            if (helper(graph, status, i))
                return false;
        }
        return true;
    }
    bool helper(vector<vector<int>>& graph, vector<int> &status, int course) {
        if (status[course] == visting)
            return true;
        else if (status[course] == visted)
            return false;
        status[course] = visting;
        for (int next : graph[course]) {
            if (helper(graph, status, next))
                return true;
        }
        status[course] = visted;
        return false;
    }
};

/*
    BFS
    Kahn's algorithm for Topological Sorting
    degree[i] denote the number of prerequisites in this course
    when degree[i]=0, means this courses don't have any prerequisites -> can be start point and recorded already visited
    every courses only be visited one times -> numCourses == 0

    T: O(V+E)/S: O(V+E)
*/
class Solution {
private:
    const int unvisted = 0, visting = 1, visted = 2;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> degree(numCourses, 0);
        for (auto v : prerequisites) {
            graph[v[1]].push_back(v[0]);
            degree[v[0]]++;
        }
        queue<int> q;
        // choose start points (degree = 0)
        for (int i = 0; i < degree.size(); ++i) {
            if (!degree[i]) {
                q.push(i);
                numCourses--;
            }
        }
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int adj : graph[cur]) {
                degree[adj]--;
                if (!degree[adj]) {
                    q.push(adj);
                    numCourses--;
                }
            }
        }
        return numCourses == 0;
    }
};


// First time
/*
    Topological Sort -> DFS (backtracking)
    Only Directed Acyclic Graph (DAG) can be topological sorted, can not have cycle

    Use Adjacency List to store the graph, and one vector to store unvisited, visiting or visited
    (Or can use two vector "todo" and "done")
    Check is cyclic or not by DFS, BTW the topological ordering will be the reverse of the result
    T: O(V+E)/S: O(V+E) -> adjlist: O(V+E), recursion: O(V)
*/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjlist(numCourses, vector<int>{});
        vector<int> visited(numCourses, 0);
        // T: O(E)
        for (auto prerequisite : prerequisites)
            adjlist[prerequisite[1]].push_back(prerequisite[0]);
        // T: O(V+E)
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
    Topological Sort -> BFS (Kahn's algorithm)
    If degree[i] == 0, means there aren't any edges connect to the node, so it can be a start point to BFS
    Choose one start point and remove all edges connected to it (subtract one of adjacent point's degree)
    If there is no cycle, all points will be pushed to the queue one time, here numCourses will become zero
    T: O(V+E)/S: O(V+E)
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