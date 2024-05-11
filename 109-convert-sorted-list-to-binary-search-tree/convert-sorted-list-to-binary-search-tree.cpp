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
    ListNode* findMid(ListNode* start, ListNode* end) {
        ListNode* fast = start;
        ListNode* slow = start;
        while (fast != end && fast->next != end) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    TreeNode* helper(ListNode* start, ListNode* end) {
        if (start == end)
            return nullptr;
        ListNode* mid = findMid(start, end);
        TreeNode* root = new TreeNode(mid->val);
        root->left = helper(start, mid);
        root->right = helper(mid->next, end);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) { return helper(head, nullptr); }
};