// First time
/*
    In every node, we have two choices
    1. when root > sum of child: take root node, remain child nodes
    2. when root < sum of child: take child nodes, remain root node
    Use dfs to return {be taken value, sum of remain value of each subtree}

    T: O(n)/S: O(n)
*/
class Solution {
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();
        vector<vector<int>> graph(n);
        for (auto e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        return dfs(graph, values, 0, -1).first;
    }
    pair<long long, long long> dfs(vector<vector<int>> &graph, vector<int> &values, int node, int parent) {
        // handle leaf node and (only two nodes case or 0 node is leaf case)
        if (graph[node].size() == 1 && node != 0)
            return {0, values[node]};
        long long take = 0, rem = 0;
        for (int adj : graph[node]) {
            if (adj != parent) {
                auto [t, r] = dfs(graph, values, adj, node);
                take += t;
                rem += r;
            }
        }
        if (values[node] > rem) {
            // we take root node, so rem don't change
            take += values[node];
            // rem = rem;
        } else {
            // we take remain nodes, so only remain root node
            take += rem;
            rem = values[node];
        }
        // // also can be represented to this
        // take += max((long long)values[node], rem);
        // rem = min((long long)values[node], rem);
        return {take, rem};
    }
};

/*
    We can compute the remain node, then use the sub of value subtract it
    So we need to let the remain value be as minimum as possible

    p.s.
    When building undirected graph, we need to add two direction node,
    because we don't know where is the root (maybe not 0),
    If its not root, it can trace back to find
    But notice to add "parent" argument in dfs() to avoid not traversing the same root again

    T: O(n)/S: O(n)
*/
class Solution {
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();
        vector<vector<int>> graph(n);
        for (auto e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        long long sum = accumulate(values.begin(), values.end(), 0LL);
        long long remain = dfs(graph, values, 0, -1);
        return sum - remain;
    }
    long long dfs(vector<vector<int>> &graph, vector<int> &values, int node, int parent) {
        // handle leaf node and (only two nodes case or 0 node is leaf case)
        if (graph[node].size() == 1 && node != 0)
            return values[node];
        long long rem = 0;
        for (int adj : graph[node]) {
            if (adj != parent) {
                rem += dfs(graph, values, adj, node);
            }
        }
        // choose we should remain parent node or child nodes
        return min(values[node] * 1LL, rem);
    }
};