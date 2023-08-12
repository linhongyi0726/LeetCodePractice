// First time
/*
    T: O(1)/S: O(1)
*/
class Solution {
public:
    bool checkTree(TreeNode* root) {
        return root->val == root->left->val + root->right->val;
    }
};