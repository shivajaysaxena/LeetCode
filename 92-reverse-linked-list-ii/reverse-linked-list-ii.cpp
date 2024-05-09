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
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int> temp;
        ListNode* ptr = head;
        while (ptr) {
            temp.push_back(ptr->val);
            ptr = ptr->next;
        }
        reverse(temp.begin() + left - 1, temp.begin() + right);
        ptr = head;
        for (int i = 0; i < temp.size(); i++) {
            ptr->val = temp[i];
            ptr = ptr->next;
        }

        return head;
    }
};