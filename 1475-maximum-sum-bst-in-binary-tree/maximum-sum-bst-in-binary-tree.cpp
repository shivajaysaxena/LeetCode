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
    int ans = 0;
    pair<int, pair<int, int>> solve(TreeNode* root) {
        if (!root)
            return {0, {INT_MAX, INT_MIN}};
        if (!root->left && !root->right) {
            ans = max(ans, root->val);
            return {root->val, {root->val, root->val}};
        }
        pair<int, pair<int, int>> lsum;
        pair<int, pair<int, int>> rsum;
        lsum = solve(root->left);
        rsum = solve(root->right);
        int suml = lsum.first;
        int sumr = rsum.first;
        int lsmallest = lsum.second.first;
        int llargest = lsum.second.second;
        int rsmallest = rsum.second.first;
        int rlargest = rsum.second.second;
        if (root->val > llargest && root->val < rsmallest) {
            ans = max(ans, root->val + suml + sumr);
            return {root->val + suml + sumr,
                    {min(root->val, lsmallest), max(root->val, rlargest)}};
        } else {
            return {0, {INT_MIN, INT_MAX}};
        }
    }
    int maxSumBST(TreeNode* root) {

        auto a = solve(root);
        return max(0, ans);
    }
};