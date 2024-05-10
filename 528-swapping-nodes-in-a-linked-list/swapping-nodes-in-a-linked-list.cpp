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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 0;
        while (temp != NULL) {
            temp = temp->next;
            count++;
        }
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        int x = count - k;
        while (k != 1) {
            temp1 = temp1->next;
            k--;
        }
        while (x != 0) {
            temp2 = temp2->next;
            x--;
        }
        int swp = temp1->val;
        temp1->val = temp2->val;
        temp2->val = swp;
        return head;
    }
};