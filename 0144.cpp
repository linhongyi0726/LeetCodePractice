// First time
/*
    Iteration with stack
    NLR

    T: O(n)/S: O(n)
*/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode *> s;
        while (root || !s.empty()) {
            if (root) {
                s.push(root);
                // N
                ret.push_back(root->val);   // add before going to children node
                // L
                root = root->left;
            } else {
                root = s.top(); // -> it's N
                s.pop();
                // R
                root = root->right;
            }
        }
        return ret;
    }
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode *> s;
        while (root || !s.empty()) {
            if (root) {
                ret.push_back(root->val);
                s.push(root->right);
                root = root->left;
            } else {
                root = s.top();
                s.pop();
            }
        }
        return ret;
    }
};

/*
    Iteration with stack
    But not the same with inorder or postorder,
    here we no need flag to identify because it's preorder
    T: O(n)/S: O(n)
*/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode *> s;
        if (root)
            s.push(root);
        while (!s.empty()) {
            auto cur = s.top();
            s.pop();
            ret.push_back(cur->val);
            if (cur->right)
                s.push(cur->right);
            if (cur->left)
                s.push(cur->left);
        }
        return ret;
    }
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
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
                if (cur.first->left)
                    s.push({cur.first->left, false});
                s.push({cur.first, true});
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
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root)
            return {};
        ret.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return ret;
    }
};