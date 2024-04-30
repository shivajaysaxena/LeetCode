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
    int length(ListNode* head) {
        int len = 0;
        while (head != NULL) {
            head = head->next;
            len++;
        }

        return len;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = length(head);

        if (len == n)
            return head->next;

        ListNode* temp = head;
        int pos = 1;
        while (pos < len - n) {
            temp = temp->next;
            pos++;
        }

        if (temp->next == NULL)
            return NULL;

        temp->next = temp->next->next;

        return head;
    }
};