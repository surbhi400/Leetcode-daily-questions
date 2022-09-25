/* Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

 

Example 1:


Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22

Example 2:


Input: root = [1,2,3], targetSum = 5
Output: []
*/------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class Solution {
public:
     vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) return {};

        vector<vector<int>> ans;
        vector<int> path;
        dfs(root, targetSum, path, ans);
        return ans;
    }

    void dfs(TreeNode* node, int targetSum, vector<int>& path,
             vector<vector<int>>& ans) {
        path.push_back(node->val);
        targetSum -= node->val;
        if (!node->left && !node->right && !targetSum) ans.push_back(path);
        if (node->left) dfs(node->left, targetSum, path, ans);
        if (node->right) dfs(node->right, targetSum, path, ans);
        path.pop_back();
    }
};
