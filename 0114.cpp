// First time
/*
    Recursion
    T: O(n)/S: O(1)
*/
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        flatten(root->left);
        flatten(root->right);
        TreeNode *right=root->right;
        root->right = root->left;
        root->left = nullptr;
        while (root->right) root=root->right;
        root->right=right;
    }
};

class Solution {
public:
    TreeNode *prev=nullptr;
    void flatten(TreeNode* root) {
        if (!root) return;
        // Here we must do right first, it will let right node link behind left node (pre-order: NLR)
        flatten(root->right);
        flatten(root->left);
        root->right=prev;
        root->left=nullptr;
        prev=root;
    }
};

/*
    Iteration
    Pre-order: NLR -> Move right node to the back of left node's right side
    T: O(n)/S: O(1)
*/
class Solution {
public:
    void flatten(TreeNode* root) {
        while (root) {
            if (root->left) {
                TreeNode *left = root->left;
                while (left->right) left=left->right;
                left->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }
            root=root->right;
        }
    }
};