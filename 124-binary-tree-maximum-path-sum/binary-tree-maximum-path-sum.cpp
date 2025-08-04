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
    int maxPtSum(TreeNode* root, int& mxsum){
        if(!root){
            return 0;
        }
        int lt=max(0,maxPtSum(root->left,mxsum));
        int rt=max(0,maxPtSum(root->right,mxsum));
        int totval=lt+rt+root->val;
        mxsum=max(mxsum,totval);
        int mxpt=max(lt,rt)+root->val;
        return mxpt;
    }
    int maxPathSum(TreeNode* root) {
        int mxsum=INT_MIN;
        maxPtSum(root,mxsum);
        return mxsum;
    }
};