// First time
/*
    DFS
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
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        
    }
};

