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
    ListNode* partition(ListNode* head, int x) {
        vector<int> temp;
        ListNode* ptr=head;
        while(ptr){
            temp.push_back(ptr->val);
            ptr=ptr->next;
        }
        vector<int> temp1;
        vector<int> temp2;
        for(int i=0;i<temp.size();i++){
            if(temp[i] < x){
                temp1.push_back(temp[i]);
            }
            else{
                temp2.push_back(temp[i]);
            }
        }
        temp.clear();
        for(int i=0;i<temp1.size();i++){
            temp.push_back(temp1[i]);
        }
        for(int i=0;i<temp2.size();i++){
            temp.push_back(temp2[i]);
        }
        for(int i=0;i<temp.size();i++){
            cout<<temp[i]<<" ";
        }
        cout<<endl;
        ptr=head;
        for(int i=0;i<temp.size();i++){
            ptr->val=temp[i];
            ptr=ptr->next;
        }
        return head;
    }
};