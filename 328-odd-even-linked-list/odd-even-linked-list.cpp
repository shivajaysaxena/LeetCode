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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddDummy = new ListNode();
        ListNode* evenDummy = new ListNode();

        ListNode* oddTail = oddDummy;
        ListNode* evenTail = evenDummy;

        ListNode* current = head;
        int index = 1;

        while (current) {
            ListNode* nextNode = current->next;

            if (index % 2 == 0) {

                evenTail->next = current;
                evenTail = current;
                current->next = nullptr;
            } else {

                oddTail->next = current;
                oddTail = current;
                current->next = nullptr;
            }

            current = nextNode;
            index++;
        }

        oddTail->next = evenDummy->next;

        head = oddDummy->next;

        return head;
    }
};