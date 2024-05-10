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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if (lists.empty())
            return NULL;

        vector<int> vect;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] == nullptr)
                continue;
            vector<int> mtx;
            ListNode* temp = lists[i];

            while (temp != nullptr) {
                mtx.push_back(temp->val);
                temp = temp->next;
            }

            vect.insert(vect.end(), mtx.begin(), mtx.end());
        }

        if (vect.empty())
            return nullptr;

        sort(vect.begin(), vect.end());

        ListNode* root = new ListNode(vect[0]);

        ListNode* curr = root;

        for (int i = 1; i < vect.size(); i++) {
            ListNode* temp = new ListNode(vect[i]);
            curr->next = temp;

            curr = curr->next;
        }

        return root;
    }
};