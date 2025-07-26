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
int lenght(ListNode* head){
    ListNode* temp=head;
    int len=0;
    while(temp){
        len++;
        temp=temp->next;
    }
    return len;
}
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l=lenght(head);
        if(l==n){
            return head->next;
        }
        int pos=1;
        ListNode* temp=head;
        while(pos<l-n){
            temp=temp->next;
            pos++;
        }
        temp->next=temp->next->next;
        return head;

    }
};