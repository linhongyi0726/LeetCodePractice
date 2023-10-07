// First time
/*
    follow-up from problem 207
    Courses have ordered relationship -> Topological Sort
    Backtracking to check having cycle or not, and record already checked node
    It will be the reversion of the answer -> because we add from last course

    T: O(V+E)/S: O(V+E)
*/
class Solution {
private:
    const int unvisted = 0, visting = 1, visted = 2;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> status(numCourses, unvisted);
        // DAG: pre-course -> next course
        for (auto v : prerequisites) {
            graph[v[1]].push_back(v[0]);
        }
        vector<int> ret;
        for (int i = 0; i < numCourses; ++i) {
            if (helper(graph, status, i, ret))
                return {};
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
    bool helper(vector<vector<int>>& graph, vector<int> &status, int course, vector<int> &ret) {
        if (status[course] == visting)
            return true;
        else if (status[course] == visted)
            return false;
        status[course] = visting;
        for (int next : graph[course]) {
            if (helper(graph, status, next, ret))
                return true;
        }
        status[course] = visted;
        ret.push_back(course);
        return false;
    }
};

/*
    BFS
    Kahn's algorithm for Topological Sorting
    degree[i] denote the number of prerequisites in this course
    degree[i]=0, means this courses don't have any prerequisites
    -> can visit and be start point, every courses can only be visited one times

    T: O(V+E)/S: O(V+E)
*/
class Solution {
private:
    const int unvisted = 0, visting = 1, visted = 2;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> degree(numCourses, 0);
        for (auto v : prerequisites) {
            graph[v[1]].push_back(v[0]);
            degree[v[0]]++;
        }
        queue<int> q;
        vector<int> ret;
        // choose start points (degree = 0)
        for (int i = 0; i < degree.size(); ++i) {
            if (!degree[i]) {
                q.push(i);
                ret.push_back(i);
            }
        }
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int adj : graph[cur]) {
                degree[adj]--;
                if (!degree[adj]) {
                    q.push(adj);
                    ret.push_back(adj);
                }
            }
        }
        return ret.size() == numCourses ? ret : vector<int>{};
    }
};