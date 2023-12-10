// First time
/*
    Iteration with stack
    LNR

    T: O(n)/S: O(n)
*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode *> s;
        while (root || !s.empty()) {
            if (root) {
                s.push(root);
                // L
                root = root->left;
            } else {
                root = s.top();
                s.pop();
                // N
                ret.push_back(root->val);   // add after going all left children node
                // R
                root = root->right;
            }
        }
        return ret;
    }
};

// start from the most left node
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode *> s;
        while (root || !s.empty()) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            ret.push_back(root->val);
            root = root->right;
        }
        return ret;
    }
};

/*
    Iteration with stack
    use flag to identify we already visited the left child of this node
    Notice to reversed push into stack (LNR -> RNL)

    T: O(n)/S: O(n)
*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<pair<TreeNode *, bool>> s;
        if (root)
            s.push({root, false});
        while (!s.empty()) {
            auto cur = s.top();
            s.pop();
            if (cur.second) {
                ret.push_back(cur.first->val);
            } else {
                if (cur.first->right)
                    s.push({cur.first->right, false});
                s.push({cur.first, true});
                if (cur.first->left)
                    s.push({cur.first->left, false});
            }
        }
        return ret;
    }
};

/*
    Recursion
    T: O(n)/S: O(n)
*/
class Solution {
public:
    vector<int> ret;
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root)
            return {};
        inorderTraversal(root->left);
        ret.push_back(root->val);
        inorderTraversal(root->right);
        return ret;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        dfs(root, ret);
        return ret;
    }
    void dfs(TreeNode *node, vector<int> &ret) {
        if (!node)
            return;
        dfs(node->left, ret);
        ret.push_back(node->val);
        dfs(node->right, ret);
    }
};