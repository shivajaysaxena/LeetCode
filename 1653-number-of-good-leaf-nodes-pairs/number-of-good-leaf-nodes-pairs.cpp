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
    vector<int> postorder(TreeNode* root, int distance, int& gp) {
        if (root == NULL)
            return {};
        if (root->left == NULL && root->right == NULL)
            return {1};

        vector<int> left = postorder(root->left, distance, gp);
        vector<int> right = postorder(root->right, distance, gp);

        int n = left.size();
        int m = right.size();
        vector<int> combined;

        for (int i = 0; i < n; i++) {
            if (left[i] > distance)
                continue;
            for (int j = 0; j < m; j++) {
                if (left[i] + right[j] <= distance)
                    gp++;
            }
        }

        for (int i = 0; i < n; i++)
            combined.push_back(left[i] + 1);
        for (int i = 0; i < m; i++)
            combined.push_back(right[i] + 1);
        return combined;
    }
    int countPairs(TreeNode* root, int distance) {
        vector<int> heights;
        int gp = 0;
        postorder(root, distance, gp);
        return gp;
    }
};