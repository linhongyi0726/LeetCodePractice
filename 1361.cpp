// First time
/*
    union-find
    T: O(n)/S: O(n)
*/
class Solution {
public:
    int find(int node, vector<int> &parent) {
        if (parent[node] == node)
            return node;
        return parent[node] = find(parent[node], parent);
    }
    void uni(int node1, int node2, vector<int> &parent, vector<int> &rank) {
        node1 = find(node1, parent);
        node2 = find(node2, parent);
        if (rank[node1] > rank[node2]) {
            parent[node2] = node1;
        } else if (rank[node1] < rank[node2]) {
            parent[node1] = node2;
        } else {
            parent[node1] = node2;
            rank[node2]++;
        }
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> parent(n, -1), rank(n, 0), degree(n, 0);
        for(int i = 0;i < n; i++)
            parent[i]=i;
        // check is there any node has multiple parent
        for (int i = 0; i < n; ++i) {
            if (leftChild[i] != -1) {
                if (++degree[leftChild[i]] > 1)
                    return false;
                uni(i, leftChild[i], parent, rank);
            }
            if (rightChild[i] != -1) {
                if (++degree[rightChild[i]] > 1)
                    return false;
                uni(i, rightChild[i], parent, rank);
            }
        }
        int root = -1, cnt = 0;
        for (int i = 0; i < n; ++i) {
            // find the root and only have one root
            if (degree[i] == 0) {
                if (root != -1)
                    return false;
                root = i;
            }
            // check is there any nodes never been visited (disconnect)
            // -> also can check cyclic
            if(parent[i] == i)
                cnt++;
        }
        return root != -1 && cnt == 1;
    }
};

/*
    BFS
    The same idea with DFS approach

    Or we can use a unordered_set to record the visited node,
    then check the set size is equal to n or not

    T: O(n)/S: O(n)
*/
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> degree(n, 0);
        // find the possible root and check is there any node has multiple parent
        for (int i = 0; i < n; ++i) {
            if (leftChild[i] != -1) {
                if (++degree[leftChild[i]] > 1)
                    return false;
            }
            if (rightChild[i] != -1) {
                if (++degree[rightChild[i]] > 1)
                    return false;
            }
        }
        // get the root
        int root = -1;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 0) {
                if (root != -1)
                    return false;
                root = i;
            }
        }
        // check every nodes has been visited
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(root);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            if (node != -1 && visited[node] == false) {
                visited[node] = true;
                q.push(leftChild[node]);
                q.push(rightChild[node]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (visited[i] == false)
                return false;
        }
        return true;
    }
};

/*
    DFS
    There are three rules to be valid binary tree
    1. There is only one root and the root maybe not 0
    2. Every nodes at most has one parent except the root
    3. All nodes are connected
    We should find the root first, then dfs to check the tree

    T: O(n)/S: O(n)
*/
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<bool> visited(n, false);
        vector<int> degree(n, 0);
        // find the possible root and check is there any node has multiple parent
        for (int i = 0; i < n; ++i) {
            if (leftChild[i] != -1) {
                if (++degree[leftChild[i]] > 1)
                    return false;
            }
            if (rightChild[i] != -1) {
                if (++degree[rightChild[i]] > 1)
                    return false;
            }
        }
        // get the root
        int root = -1;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 0) {
                if (root != -1)
                    return false;
                root = i;
            }
        }
        // check every nodes has been visited
        dfs(leftChild, rightChild, visited, root);
        for (int i = 0; i < n; ++i) {
            if (visited[i] == false)
                return false;
        }
        return true;
    }
    void dfs(vector<int> &leftChild, vector<int> &rightChild, vector<bool> &visited, int root) {
        if (root == -1 || visited[root] == true)
            return;
        visited[root] = true;
        dfs(leftChild, rightChild, visited, leftChild[root]);
        dfs(leftChild, rightChild, visited, rightChild[root]);
        return;
    }
};

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<bool> visited(n, false);
        vector<bool> node(n, false);
        // find the possible root
        for (int i = 0; i < n; ++i) {
            if (leftChild[i] != -1)
                node[leftChild[i]] = true;
            if (rightChild[i] != -1)
                node[rightChild[i]] = true;
        }
        // get the root
        int root = -1;
        for (int i = 0; i < n; ++i) {
            if (node[i] == false)
                root = i;
        }
        if (root == -1)
            return false;
        visited[root] = true;
        // check any node has multiple parent
        if (dfs(n, leftChild, rightChild, visited, root)) {
            // check every node is visited
            for (int i = 0; i < n; ++i) {
                if (visited[i] == 0)
                    return false;
            }
            return true;
        } else {
            return false;
        }
    }
    bool dfs(int n, vector<int> &leftChild, vector<int> &rightChild, vector<bool> &visited, int i) {
        if (i == n)
            return true;
        int left = true, right = true;
        if (leftChild[i] != -1) {
            if(visited[leftChild[i]] == false) {
                visited[leftChild[i]] = true;
                left = dfs(n, leftChild, rightChild, visited, leftChild[i]);
            } else {
                left = false;
            }
        }
        if (rightChild[i] != -1) {
            if (visited[rightChild[i]] == false) {
                visited[rightChild[i]] = true;
                right = dfs(n, leftChild, rightChild, visited, rightChild[i]);
            } else {
                right = false;
            }
        }
        return left && right;
    }
};