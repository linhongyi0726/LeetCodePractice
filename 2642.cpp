// First time
/*
    Floyd-Warshall
    Calculate the shortest distance when init Graph and addEdge()

    T: O(V^3)/S: O(V^2)
    init: T: O(V^3)/S: O(V^2)
    addEdge: T: O(V^2)/S: O(1)
    shortestPath: T: O(1)/S: O(1)
*/
class Graph {
public:
    vector<vector<int>> dist;
    Graph(int n, vector<vector<int>>& edges) {
        dist = vector<vector<int>>(n, vector<int>(n, 1e8));
        // init the dist from giving argument
        for (int i = 0; i < n; ++i)
            dist[i][i] = 0;
        for (auto edge : edges)
            dist[edge[0]][edge[1]] = edge[2];
        // calculate the shortest dist
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    
    void addEdge(vector<int> edge) {
        int n = dist.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][edge[0]] + edge[2] + dist[edge[1]][j]);
            }
        }
    }
    
    int shortestPath(int node1, int node2) {
        if (dist[node1][node2] != 1e8)
            return dist[node1][node2];
        return -1;
    }
};

/*
    Dijkstra's algorithm
    Calculate the shortest distance when calling shortestPath()

    T: O(ElogE)/S: O(V+E)
    init: T: O(E)/S: O(V+E)
    addEdge: T: O(1)/S: O(1)
    shortestPath: T: O(ElogE)/S: O(E)
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