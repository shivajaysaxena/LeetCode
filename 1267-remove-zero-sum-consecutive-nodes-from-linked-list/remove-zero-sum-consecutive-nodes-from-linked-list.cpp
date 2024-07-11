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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* current = dummy;
        while (current != nullptr) {
            ListNode* ptr = current->next;
            int sum = 0;
            while (ptr != nullptr) {
                sum += ptr->val;
                if (sum == 0) {
                    current->next = ptr->next;
                }
                ptr = ptr->next;
            }
            current = current->next;
        }
        return dummy->next;
    }
};