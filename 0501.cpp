// First time
/*
    With out using hash map, use the property of binary search tree
    left < root < right
    So if the previous value is different with current,
    means the previous value all have been counted already (we can initialize cnt to 1)
    *Notice we must use inorder traversal here
    T: O(n)/S: O(n)
*/
class Solution {
public:
    vector<int> ret;
    int cnt = 0, mx = 0, prev = INT_MIN;
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return ret;
    }
    // inorder traversal
    void dfs(TreeNode *node) {
        if (!node)
            return;
        dfs(node->left);
        if (node->val == prev)
            cnt++;
        else
            cnt = 1;
        if (cnt > mx) {
            ret = {node->val};
            mx = cnt;
        } else if (cnt == mx){
            ret.push_back(node->val);
        }
        prev = node->val;
        dfs(node->right);
    }
};

/*
    Use hash map to store the count of each node's value
    T: O(n)/S: O(n)
*/
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> mp;
        int mx = 0;
        dfs(root, mp, mx);
        vector<int> ret;
        for (auto it : mp) {
            if (it.second == mx)
                ret.push_back(it.first);
        }
        return ret;
    }
    void dfs(TreeNode *node, unordered_map<int, int> &mp, int &mx) {
        if (!node)
            return;
        mp[node->val]++;
        mx = max(mx, mp[node->val]);
        dfs(node->left, mp, mx);
        dfs(node->right, mp, mx);
    }
};

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> mp;
        int mx = dfs(root, mp);
        vector<int> ret;
        for (auto it : mp) {
            if (it.second == mx)
                ret.push_back(it.first);
        }
        return ret;
    }
    int dfs(TreeNode *node, unordered_map<int, int> &mp) {
        if (!node)
            return 0;
        return max({++mp[node->val], dfs(node->left, mp), dfs(node->right, mp)});
    }
};