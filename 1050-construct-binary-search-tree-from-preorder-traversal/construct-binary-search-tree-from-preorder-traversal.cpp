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
    int findind(vector<int>& preorder, int key, int l, int r) {
        for (int i = l; i <= r; i++) {
            if (i != 0 && preorder[i] > key)
                return i - 1;
        }
        return r;
    }
    TreeNode* solve(int l, int r, vector<int>& preorder) {
        if (l > r)
            return NULL;
        TreeNode* node = new TreeNode(preorder[l]);
        int ind = findind(preorder, preorder[l], l + 1, r);
        node->left = solve(l + 1, ind, preorder);
        node->right = solve(ind + 1, r, preorder);
        return node;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.size() == 0)
            return NULL;
        return solve(0, preorder.size() - 1, preorder);
    }
};