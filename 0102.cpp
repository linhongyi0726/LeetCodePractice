// First time
/*
    BFS by queue (Levelorder traversal)
    T: O(n)/S: O(n)
*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        vector<int> level;
        if (root) q.push(root);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                TreeNode* node = q.front(); q.pop();
                level.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans.push_back(level);
            level.clear();
        }
        return ans;
    }
};

/*
    Preorder traversal (also can use postorder, just need to modify ans push back timing)
    T: O(n)/S: O(n)
*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        preorder(root, 0, ans);
        return ans
    }
    void preorder(TreeNode* node, int level, vector<vector<int>> &ans) {
        if (!node) return;
        if (ans.size() <= level) ans.push_back({});
        ans[level].push_back(node->val);
        preorder(node->left, level+1, ans);
        preorder(node->right, level+1, ans);
    }
};