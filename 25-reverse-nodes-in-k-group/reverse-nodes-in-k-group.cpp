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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* current = head;
        vector<int> retarr;
        while (current != NULL) {
            retarr.push_back(current->val);
            current = current->next;
        }
        int gap = k;
        int reverse_gap = k;
        int a = 0;
        int i = 0;
        while (i < retarr.size() / gap) {
            reverse(retarr.begin() + a, retarr.begin() + k);
            a += reverse_gap;
            k += reverse_gap;
            i++;
        }
        ListNode* answer = new ListNode();
        ListNode* traverse = answer;
        for (int i = 0; i < retarr.size(); i++) {
            traverse->next = new ListNode(retarr[i]);
            traverse = traverse->next;
        }
        return answer->next;
    }
};