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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> st;
        for (auto x : nums) {
            st.insert(x);
        }

        ListNode* d = new ListNode(-1);
        ListNode* temp = d;
        while (head != NULL) {
            if (st.find(head->val) == st.end()) {
                temp->next = head;
                temp = temp->next;
            }
            head = head->next;
        }
        temp->next = NULL;
        return d->next;
    }
};