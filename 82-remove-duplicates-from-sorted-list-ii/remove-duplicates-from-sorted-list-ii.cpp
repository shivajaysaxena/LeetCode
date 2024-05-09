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
        if (!head)
            return nullptr;
        unordered_map<int, int> freq;
        ListNode* current = head;
        while (current) {
            freq[current->val]++;
            current = current->next;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        current = head;
        while (current) {
            if (freq[current->val] == 1) {
                prev->next = current;
                prev = prev->next;
            }
            current = current->next;
        }
        prev->next = nullptr; 
        return dummy->next;
    }
};