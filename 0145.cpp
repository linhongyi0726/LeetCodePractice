// First time
/*
    Iteration with stack
    An innovative approach: double push the node to stack
    one node can be used to expend to left node and right node,
    and the other one can be used as parent node

    T: O(n)/S: O(n)
*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode *> s;
        if (root) {
            s.push(root);
            s.push(root);
        }
        while (!s.empty()) {
            auto cur = s.top();
            s.pop();
            if (!s.empty() && cur == s.top()) {
                if (cur->right) {
                    s.push(cur->right);
                    s.push(cur->right);
                }
                if (cur->left) {
                    s.push(cur->left);
                    s.push(cur->left);
                }
            } else {
                ret.push_back(cur->val);
            }
        }
        return ret;
    }
};

/*
    Iteration with stack
    Use another variable to store the last node we visited,
    to avoid re-visited the right node

    T: O(n)/S: O(n)
*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode *> s;
        TreeNode *pre = nullptr;
        while (root || !s.empty()) {
            if (root) {
                s.push(root);
                root = root->left;
            } else {
                auto cur = s.top();
                if (cur->right && cur->right != pre) {
                    root = cur->right;
                } else {
                    s.pop();
                    ret.push_back(cur->val);
                    pre = cur;
                }
            }
        }
        return ret;
    }
};

/*
    Iteration with stack
    It's hard to LRN traverse,
    so we can do NRL traverse then reverse the result at the end,
    or add the result in the begin when we traverse

    T: O(n)/S: O(n)
*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode *> s;
        while (root || !s.empty()) {
            if (root) {
                s.push(root);
                // N
                ret.push_back(root->val);
                // R
                root = root->right;
            } else {
                root = s.top();
                s.pop();
                // L
                root = root->left;
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode *> s;
        while (root || !s.empty()) {
            if (root) {
                s.push(root);
                // N
                ret.insert(ret.begin(), root->val);
                // R
                root = root->right;
            } else {
                root = s.top();
                s.pop();
                // L
                root = root->left;
            }
        }
        return ret;
    }
};

/*
    Iteration with stack
    use flag to identify we already visited the left child of this node
    Notice to reversed push into stack (LRN -> NRL)
    T: O(n)/S: O(n)
*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
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
                s.push({cur.first, true});
                if (cur.first->right)
                    s.push({cur.first->right, false});
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
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root)
            return {};
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        ret.push_back(root->val);
        return ret;
    }
};