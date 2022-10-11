// First time
/*
    DFS
    Use recursion instead of stack to DFS and hash map to store the node already be copied
    T: O(vertex + edge) -> adjacency list
    S: O(V)
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> visit;
    Node* cloneGraph(Node* node) {
        if (!node) return 0;
        if (!visit.count(node)) {
            visit[node] = new Node(node->val);
            for (auto neighbor : node->neighbors)
                visit[node]->neighbors.push_back(cloneGraph(neighbor));
        }
        return visit[node];
    }
};

/*
    BFS
    Use queue to BFS and hash map to store the node already be copied
    T: O(V+E)/S: O(V)
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return 0;
        unordered_map<Node*, Node*> visit;
        queue<Node*> q;
        visit[node] = new Node(node->val);
        q.push(node);
        while(!q.empty()) {
            Node* cur = q.front(); q.pop();
            for (auto neighbor : cur->neighbors) {
                if (!visit.count(neighbor)) {
                    visit[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                visit[cur]->neighbors.push_back(visit[neighbor]);
            }
        }
        return visit[node];
    }
};

