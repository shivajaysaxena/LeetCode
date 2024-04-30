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
    int maxPathTotal(TreeNode*root,int &maxSum){
        if(root==NULL) {
            return 0;
        }
        int leftSubTreeSum = max(0,maxPathTotal(root->left,maxSum));
        int rightSubTreeSum = max(0,maxPathTotal(root->right,maxSum));
        int totalSumAtNode = leftSubTreeSum + rightSubTreeSum + root->val ;
        maxSum = max(maxSum,totalSumAtNode);
        int maxPossiblePath = root->val + max(leftSubTreeSum,rightSubTreeSum);
        return maxPossiblePath;
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
         maxPathTotal(root,maxSum);
         return maxSum;
    }
};