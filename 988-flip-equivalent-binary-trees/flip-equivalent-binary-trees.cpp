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
    bool dfs(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr)
            return true;
        if (root1 == nullptr && root2 != nullptr)
            return false;
        if (root2 == nullptr && root1 != nullptr)
            return false;
        if (root1->val != root2->val)
            return false;

        bool flag = false;
        flag = flag || (dfs(root1->left, root2->left) &&
                        dfs(root1->right, root2->right));
        flag = flag || (dfs(root1->left, root2->right) &&
                        dfs(root1->right, root2->left));
        return flag;
    }

public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return dfs(root1, root2);
    }
};