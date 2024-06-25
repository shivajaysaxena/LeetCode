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
private:
    void f(TreeNode* root, int& sum) {
        if (!root)
            return;

        f(root->right, sum);
        int copy = root->val;
        root->val += sum;
        sum += copy;
        f(root->left, sum);
    }

public:
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        f(root, sum);
        return root;
    }
};