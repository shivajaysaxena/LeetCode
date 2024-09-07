/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    vector<vector<int>> v;
    bool pathall(TreeNode* root, ListNode* head) {
        if (head == nullptr)
            return true;
        if (root == nullptr)
            return false;
        if (head->val != root->val)
            return false;
        bool a = pathall(root->left, head->next);
        bool b = pathall(root->right, head->next);
        return a || b;
    }
    bool finalpath(TreeNode* root, ListNode* head) {

        if (root == nullptr) {
            return false;
        }
        bool a = pathall(root, head);
        bool b = finalpath(root->left, head);
        bool c = finalpath(root->right, head);
        return a || b || c;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (root == nullptr)
            return false;
        return finalpath(root, head);
    }
};