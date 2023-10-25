// First time
/*
    DFS
    Use ret.size() to check this loop is more than previous depth or not
    T: O(n)/S: O(n)
*/
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ret;
        dfs(root, ret, 0);
        return ret;
    }
    void dfs(TreeNode* node, vector<int> &ret, int depth) {
        if (!node)
            return;
        /*
        if (depth == ret.size())
            ret.resize(depth + 1, INT_MIN);
        ret[depth] = max(ret[depth], node->val);
        */
        if (depth == ret.size()) {
            ret.push_back(node->val);
        } else {
            ret[depth] = max(ret[depth], node->val);
        }
        dfs(node->left, ret, depth + 1);
        dfs(node->right, ret, depth + 1);
    }
};

/*
    BFS
    for loop to traverse every layer and compute the maximum
    T: O(n)/S: O(n)
*/
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (!root)
            return {};
        vector<int> ret;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size(), mx = INT_MIN;
            for (int i = 0; i < n; ++i) {
                auto cur = q.front();
                q.pop();
                mx = max(mx, cur->val);
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            ret.push_back(mx);
        }
        return ret;
    }
};