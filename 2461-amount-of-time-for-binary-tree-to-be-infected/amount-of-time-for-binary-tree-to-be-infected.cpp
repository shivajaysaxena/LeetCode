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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, pair<TreeNode*, pair<TreeNode*, TreeNode*>>>
            freq;

        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root, nullptr});

        while (!q.empty()) {
            TreeNode* temp = q.front().first;
            TreeNode* par = q.front().second;
            q.pop();

            freq[temp] = {par, {temp->left, temp->right}};

            if (temp->left)
                q.push({temp->left, temp});
            if (temp->right)
                q.push({temp->right, temp});
        }

        TreeNode* head = nullptr;
        for (auto it : freq) {
            if (it.first->val == start) {
                head = it.first;
                break;
            }
        }

        int ans = 0;
        queue<pair<TreeNode*, int>> qu;
        qu.push({head, 0});

        while (!qu.empty()) {
            TreeNode* curr = qu.front().first;
            int cnt = qu.front().second;
            qu.pop();

            ans = max(ans, cnt);

            auto it = freq.find(curr);
            if (it == freq.end())
                continue;
            auto [parent, children] = it->second;
            freq.erase(curr);

            if (parent && freq.count(parent))
                qu.push({parent, cnt + 1});
            if (children.first && freq.count(children.first))
                qu.push({children.first, cnt + 1});
            if (children.second && freq.count(children.second))
                qu.push({children.second, cnt + 1});
        }

        return ans;
    }
};