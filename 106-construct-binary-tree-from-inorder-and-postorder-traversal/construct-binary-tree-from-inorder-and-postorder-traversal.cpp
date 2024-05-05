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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, postorder, 0, inorder.size() - 1, 0,
                     postorder.size() - 1);
    }

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int inStart,
                    int inEnd, int postStart, int postEnd) {
        if (inStart > inEnd)
            return nullptr;
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int index = inStart;
        while (inorder[index] != root->val)
            index++;
        int leftLen = index - inStart;
        root->left = build(inorder, postorder, inStart, index - 1, postStart,
                           postStart + leftLen - 1);
        root->right = build(inorder, postorder, index + 1, inEnd,
                            postStart + leftLen, postEnd - 1);
        return root;
    }
};