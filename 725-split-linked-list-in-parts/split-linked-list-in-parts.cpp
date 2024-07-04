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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode* cur = head;
        while (cur != NULL) {
            ++len;
            cur = cur->next;
        }
        vector<ListNode*> res(k, NULL);
        int sz = len / k;
        int rem = len % k;

        ListNode* curr = head;
        ListNode* prev = NULL;
        for (int i = 0; i < k; i++) {
            res[i] = curr;
            for (int j = 0; j < sz; j++) {
                prev = curr;
                curr = curr->next;
            }
            if (rem > 0) {
                if (curr != NULL) {
                    prev = curr;
                    curr = curr->next;
                    --rem;
                }
            }
            if (prev != NULL) {
                head = curr;
                prev->next = NULL;
            }
        }
        return res;
    }
};