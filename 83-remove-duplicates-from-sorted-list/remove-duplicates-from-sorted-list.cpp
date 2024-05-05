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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* headtwo = head;
        ListNode* ans = head;
        if (head == NULL)
            return head;
        while (headtwo != NULL) {
            if (head->val != headtwo->val) {
                head->next = headtwo;
                head = head->next;
            }
            headtwo = headtwo->next;
        }
        head->next = NULL;
        return ans;
    }
};