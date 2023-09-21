// First time
/*
    DFS
    Use a array or hash map to record the most left node's index
    ex.
    left: [1, 2, 4]
    0, [1, 2, 3, 4, 5, 6, 7]
         1
       /   \
      2     3
     / \   / \
    4   5 6   7

    T: O(n)/S: O(n)
*/
class Solution {
public:
    void helper(TreeNode *node, unsigned int idx, vector<int> &left, int depth, int &ret) {
        if (!node)
            return;
        if (depth >= left.size())
            left.push_back(idx);
        ret = max(ret, (int)(idx - left[depth] + 1));
        helper(node->left, idx * 2, left, depth + 1, ret);
        helper(node->right, idx * 2 + 1, left, depth + 1, ret);
    }
    int widthOfBinaryTree(TreeNode* root) {
        // index: high(depth) of tree, value: the most left node's index
        vector<int> left;
        int ret = 0;
        helper(root, 1, left, 0, ret);
        return ret;
    }
};

/*
    BFS
    Use queue to do level order traversal
    Represent the binary tree to an array, the children of node will be idx*2 and idx*2+1
    0, [1, 2, 3, 4, 5, 6, 7]
         1
       /   \
      2     3
     / \   / \
    4   5 6   7
    *Note to use unsigned int to avoid overflow,
    although the answer will in the rage of 32-bit signed integer,
    but we count the tree idx from 1, so INT_MAX+1 will overflow
    T: O(n)/S: O(n)
*/
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        // {Node, idx}
        queue<pair<TreeNode *, unsigned int>> q;
        int ret = 0;
        if (root)
            q.push({root, 1});
        while (!q.empty()) {
            unsigned int l = q.front().second, r = l, n = q.size();
            for (int i = 0; i < n; ++i) {
                TreeNode *node = q.front().first;
                r = q.front().second;
                q.pop();
                if (node->left)
                    q.push({node->left, r * 2});
                if (node->right)
                    q.push({node->right, r * 2 + 1});
            }
            ret = max(ret, (int)(r - l + 1));
        }
        return ret;
    }
};