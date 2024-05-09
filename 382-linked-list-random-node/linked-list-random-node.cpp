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
    ListNode* temp;
    int n = 0;
    Solution(ListNode* head) {
        temp = head;
        while (head != NULL) {
            head = head->next;
            n++;
        }
    }

    int getRandom() {
        int x = ((int)rand() % n);
        ListNode* head = temp;
        while (head) {
            if (x == 0) {
                return head->val;
            }
            head = head->next;
            x--;
        }
        return temp->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */