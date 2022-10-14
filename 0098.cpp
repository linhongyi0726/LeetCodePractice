// First time
/*
    Valid BST:
    left < root < right
    1. Preorder traversal
    2. Inorder traversal
    3. Postorder traversal
    4. morris traversal (TODO)
        T: O(n)/S: O(1)
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

/*
    Preorder traversal
    Compare previous node and next node
    T: O(n)/S: O(n)
*/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return preorder(root, LONG_MIN, LONG_MAX);
    }
    bool preorder(TreeNode* root, long pre, long next) {
        if (!root) return true;
        if (pre >= root->val || root->val >= next) return false;
        return preorder(root->left, pre, root->val) && preorder(root->right, root->val, next);
    }
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return preorder(root, NULL, NULL);
    }
    bool preorder(TreeNode* root, TreeNode* pre, TreeNode* next) {
        if (!root) return true;
        if ((pre && pre->val >= root->val) || (next && root->val >= next->val)) return false;
        return preorder(root->left, pre, root) && preorder(root->right, root, next);
    }
};

/*
    Inorder traversal
    1. Store number in a vector and this vector will be ascending ordered
        T: O(n)/S: O(n)
    2. Use variable to save previous node to reduce space complexity
        T: O(n)/S: O(1)
*/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> v;
        inorder(root, v);
        for (int i = 0; i < v.size()-1; ++i) {
            if (v[i] >= v[i+1]) return false;
        }
        return true;
    }
    void inorder(TreeNode* root, vector<int>& v) {
        if (!root) return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right,v);
        return;
    }
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* pre = NULL;
        return inorder(root, pre);
    }
    bool inorder(TreeNode* root, TreeNode*& pre) {
        if (!root) return true;
        if (!inorder(root->left, pre)) return false;
        if (pre && pre->val >= root->val) return false;
        pre = root;
        if (!inorder(root->right, pre)) return false;
        return true;
    }
};

/*
    Postorder traversal
    return <min,max> by postorder
    T: O(n)/S: O(n)
*/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        bool ans = true;
        postorder(root, ans);
        return ans;
    }
    pair<long,long> postorder(TreeNode* root, bool& ans) {
        if (!root) return {LONG_MAX, LONG_MIN};
        auto left = postorder(root->left, ans);
        auto right = postorder(root->right, ans);
        if (left.second >= root->val || root->val >= right.first)
            ans = false;
        return {min(left.first, (long)root->val), max(right.second, (long)root->val)};
    }
};