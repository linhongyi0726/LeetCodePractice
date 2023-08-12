// First time
/*
    max(left, right)+1 -> Need to plus root node hight
*/
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool ret = true;
        helper(root, &ret);
        return ret;
    }

    int helper(TreeNode* root, bool* ret) {
        if (!root) return 0;
        int left = helper(root->left, ret);
        int right = helper(root->right, ret);
        if (abs(left-right) > 1) *ret = false;
        return max(left, right)+1;
    }
};