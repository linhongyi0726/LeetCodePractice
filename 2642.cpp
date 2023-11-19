// First time
/*
    Floyd-Warshall
*/


/*
    Dijkstra's algorithm
    T: O((V+E)*log(E))/S: O(V+E)
*/
class Graph {
public:
    vector<vector<pair<int, int>>> graph;
    Graph(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        for (auto e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        graph[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        int n = graph.size();
        // pq: {dist, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n, INT_MAX);
        dist[node1] = 0;
        pq.push({0, node1});
        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (node == node2)
                return d;
            // we have visited it, so it has smaller distance already
            // don't need to traverse its adjacent node again
            if (d > dist[node])
                continue;
            for (auto &[adj, length] : graph[node]) {
                if (d + length < dist[adj]) {
                    dist[adj] = d + length;
                    pq.push({dist[adj], adj});
                }
            }
        }
        // if there is a cycle, we can't reach node2
        return -1;
    }
};