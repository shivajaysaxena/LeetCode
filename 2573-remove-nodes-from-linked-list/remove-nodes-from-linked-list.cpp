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
    int i = 0;
    ListNode* removeNodes(ListNode* head) {
        if (i == 0 && head->next != NULL && head->next->next == NULL) {
            if (head->val < head->next->val)
                head = head->next;
            return head;
        }
        i++;
        if (head->next->next == NULL) {
            return head;
        }
        removeNodes(head->next);
        if (head->next->val < head->next->next->val) {
            head->next = head->next->next;
        }
        if (head->val < head->next->val) {
            head = head->next;
        }
        return head;
    }
};