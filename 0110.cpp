// First time
/*
    max(left, right)+1 -> Need to plus root node hight
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
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