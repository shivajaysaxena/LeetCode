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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root, NULL});
        while (!q.empty()) {
            int n = q.size();
            map<TreeNode*, int> mp;
            int totalsum = 0;
            vector<pair<TreeNode*, TreeNode*>> vc;
            for (int i = 0; i < n; i++) {
                auto cur = q.front();
                q.pop();
                totalsum += cur.first->val;
                mp[cur.second] += cur.first->val;
                vc.push_back(cur);
                if (cur.first->left)
                    q.push({cur.first->left, cur.first});
                if (cur.first->right)
                    q.push({cur.first->right, cur.first});
            }
            for (auto it : vc)
                it.first->val = totalsum - mp[it.second];
        }
        return root;
    }
};