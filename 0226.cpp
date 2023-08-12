// First time
/*
    Recursive
    DFS
*/
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

/*
    Iterative
    DFS: use stack to implement
    BFS: use queue to implement
*/
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* tmp = s.top();
            s.pop();
            swap(tmp->left, tmp->right);
            if (tmp->left)
                s.push(tmp->left);
            if (tmp->right)
                s.push(tmp->right);
        }
        return root;
    }
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* tmp = q.front();
            q.pop();
            swap(tmp->left, tmp->right);
            if (tmp->left)
                q.push(tmp->left);
            if (tmp->right)
                q.push(tmp->right);
        }
        return root;
    }
};