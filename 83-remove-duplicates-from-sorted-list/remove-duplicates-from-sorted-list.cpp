class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;

        while (curr != NULL && curr->next != NULL) {
            ListNode* temp = curr->next;
            if (curr->val == temp->val)
                curr->next = temp->next;
            else
                curr = curr->next;
        }
        return head;
    }
};