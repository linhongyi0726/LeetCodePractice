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