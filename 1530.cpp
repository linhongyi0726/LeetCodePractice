// First time
/*
    postorder traversal
    record left leaf and right leaf distance in the array,
    then combine them and return it to parent
    T: (n*n^2)/S: O(n)
*/
class Solution {
public:
    vector<int> dfs(TreeNode *root, int distance, int &ans) {
        if (!root)
            return {};
        // the distance between leaf node and its parent is 1
        if (!root->left && !root->right)
            return {1};

        // check the "good leaf node"
        vector<int> left = dfs(root->left, distance, ans);
        vector<int> right = dfs(root->right, distance, ans);
        for (int i = 0; i < left.size(); ++i) {
            for (int j = 0; j < right.size(); ++j) {
                if (left[i] + right[j] <= distance)
                    ans++;
            }
        }
        // combine left and right distance, add 1 because of root node itself
        vector<int> v;
        for (int n : left)
            v.push_back(n + 1);
        for (int n : right)
            v.push_back(n + 1);
        return v;
    }
    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        dfs(root, distance, ans);
        return ans;
    }
};