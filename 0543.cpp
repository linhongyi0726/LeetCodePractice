// First time
/*
    postorder traversal (the same with problem 110)
    left and right means how many nodes at that side
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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        postorder(root, ans);
        return ans;
    }
    int postorder(TreeNode* node, int& ans) {
        if (!node) return 0;
        int left = postorder(node->left, ans);
        int right = postorder(node->right, ans);
        ans = max(ans, left+right);
        return max(left, right)+1;
    }
};