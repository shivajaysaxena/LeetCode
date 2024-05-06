/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode* root, int targetSum, int currSum) {
        if (root == NULL) {
            return false;
        }

        currSum += root->val;

        if (root->left == NULL && root->right == NULL && currSum == targetSum) {
            return true;
        }

        bool leftAns = solve(root->left, targetSum, currSum);
        bool rightAns = solve(root->right, targetSum, currSum);

        return (leftAns || rightAns);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root, targetSum, 0);
    }
};