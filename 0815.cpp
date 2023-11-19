// First time
/*
    BFS
    Use hash map to store the relation between stop and bus

    T: O(V+E)/S: O(V+E)
*/
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target)
            return 0;
        unordered_map<int, vector<int>> stop2bus;
        int ret = 0;
        for (int i = 0; i < routes.size(); ++i) {
            for (int j = 0; j < routes[i].size(); ++j) {
                stop2bus[routes[i][j]].push_back(i);
            }
        }
        unordered_set<int> visitedbus;
        unordered_set<int> visitedstop;
        queue<int> q;
        q.push(source);
        visitedstop.insert(source);
        while (!q.empty()) {
            int n = q.size();
            ret++;
            while (n--) {
                int cur = q.front();
                q.pop();
                for (int bus : stop2bus[cur]) {
                    if (visitedbus.count(bus))
                        continue;
                    visitedbus.insert(bus);
                    for (int i = 0; i < routes[bus].size(); ++i) {
                        int stop = routes[bus][i];
                        if (stop == target)
                            return ret;
                        if (!visitedstop.count(stop)) {
                            visitedstop.insert(stop);
                            q.push(stop);
                        }
                    }
                }
            }
        }
        return -1;
    }
};

// clear the bus route which has been visited to reduce the space complexity
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target)
            return 0;
        unordered_map<int, vector<int>> stop2bus;
        int ret = 0;
        for (int i = 0; i < routes.size(); ++i) {
            for (int j = 0; j < routes[i].size(); ++j) {
                stop2bus[routes[i][j]].push_back(i);
            }
        }
        unordered_set<int> visitedstop;
        queue<int> q;
        q.push(source);
        visitedstop.insert(source);
        while (!q.empty()) {
            int n = q.size();
            ret++;
            while (n--) {
                int cur = q.front();
                q.pop();
                for (int bus : stop2bus[cur]) {
                    for (int i = 0; i < routes[bus].size(); ++i) {
                        int stop = routes[bus][i];
                        if (stop == target)
                            return ret;
                        if (!visitedstop.count(stop)) {
                            q.push(stop);
                            visitedstop.insert(stop);
                        }
                    }
                    routes[bus].clear();
                }
            }
        }
        return -1;
    }
};