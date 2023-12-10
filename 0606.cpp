// First time
/*
    It is slower because we need to create and combine whole string in every nodes
    T: O(n^2)/S: O(n)
*/
class Solution {
public:
    string tree2str(TreeNode* root) {
        if (!root)
            return "";
        string ret = to_string(root->val);
        if (root->left)
            ret += '(' + tree2str(root->left) + ')';
        if (root->right) {
            if (!root->left)
                ret += "()";
            ret += '(' + tree2str(root->right) + ')';
        }
        return ret;
    }
};

/*
    [1,2,3,4]
      1  (2(4)) (3)
      ^    ^     ^
    root  left  right
    T: O(n)/S: O(n)
*/
class Solution {
public:
    string tree2str(TreeNode* root) {
        string ret = "";
        dfs(root, ret);
        return ret;
    }
    void dfs(TreeNode *node, string &ret) {
        ret += to_string(node->val);
        if (node->left) {
            ret += '(';
            dfs(node->left, ret);
            ret += ')';
        }
        if (node->right) {
            if (!node->left)
                ret += "()";
            ret += '(';
            dfs(node->right, ret);
            ret += ')';
        }
        return;
    }
};

class Solution {
public:
    string tree2str(TreeNode* root) {
        string ret = "";
        dfs(root, ret);
        return ret.substr(1, ret.length() - 2);
    }
    void dfs(TreeNode *node, string &ret) {
        if (!node)
            return;
        ret += '(' + to_string(node->val);
        dfs(node->left, ret);
        if (!node->left && node->right)
            ret += "()";
        dfs(node->right, ret);
        ret += ')';
        return;
    }
};