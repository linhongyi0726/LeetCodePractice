// First time
/*
    Use dfs() to return {sum, cnt} to compute the average
    T: O(n)/S: O(n)
*/
class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        int ret = 0;
        dfs(root, ret);
        return ret;
    }
    pair<int, int> dfs(TreeNode *node, int &ret) {
        if (!node)
            return {0, 0};
        auto l = dfs(node->left, ret);
        auto r = dfs(node->right, ret);
        int sum = node->val + l.first + r.first;
        int cnt = 1 + l.second + r.second;
        if (sum / cnt == node->val)
            ret++;
        return {sum, cnt};
    }
};