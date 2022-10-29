// Second time
/*
    Return from problem 236
    Not use binary search tree property, just preorder traverse and find where p & q is
    T: O(n)/S: O(n)
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left && right) return root;
        else if (!left && !right) return NULL;
        return left ? left : right;
    }
};

// First time
/*
    Utilize binary search tree property:
    p->val < root->val < q->val
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
    Recursion
    T: O(h)/ S:O(h)
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val > q->val)
            swap(p,q);
        if (p->val <= root->val && root->val <= q->val)
            return root;
        else if (q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        else if (root->val < p->val)
            return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};

/*
    Iteration
    T: O(h)/ S:O(1)
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val > q->val)
            swap(p,q);
        while (!(p->val <= root->val && root->val <= q->val)) {
            if (q->val < root->val)
                root = root->left;
            else if (root->val < p->val)
                root = root->right;
        }
        return root;
    }
};