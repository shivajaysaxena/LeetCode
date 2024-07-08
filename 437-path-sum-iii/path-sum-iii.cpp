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
    int Count = 0;

public:
    int pathSum(TreeNode* a, int targetSum) {
        if (!a)
            return 0;
        PathFromRoot(a, targetSum, 0, Count);
        pathSum(a->left, targetSum);
        pathSum(a->right, targetSum);

        return Count;
    }

private:
    void PathFromRoot(TreeNode* a, int target, long Sum, int& Count) {
        if (!a)
            return;
        Sum += a->val;
        if (Sum == target)
            Count++;
        PathFromRoot(a->left, target, Sum, Count);
        PathFromRoot(a->right, target, Sum, Count);
    }
};