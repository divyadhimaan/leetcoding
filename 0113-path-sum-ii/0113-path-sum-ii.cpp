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

    void pathSumUtil(TreeNode* root, int targetSum, vector<int> &currPath, vector<vector<int>> &allPaths){
        if(!root)
            return;

        targetSum -= root->val;

        currPath.push_back(root->val);

        if(targetSum == 0 && !root->left && !root->right)
            allPaths.push_back(currPath);


        pathSumUtil(root->left, targetSum, currPath, allPaths);
        pathSumUtil(root->right, targetSum, currPath, allPaths);
        currPath.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> allPaths;
        vector<int> currPath;

        pathSumUtil(root, targetSum, currPath, allPaths);
        return allPaths;
    }
};