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
    int res = 0;
    int TotalCnt(TreeNode* root, int cost) {
        if (root == NULL)
            return 0;
        cost = cost + root->val;
        if (root->left == NULL && root->right == NULL) {
            res = res + cost;
            return cost;
        }
        TotalCnt(root->left, int(cost * 10));
        TotalCnt(root->right, int(cost * 10));
        return cost;
    }

    int sumNumbers(TreeNode* root) {
        TotalCnt(root, 0);
        return res;
    }
};