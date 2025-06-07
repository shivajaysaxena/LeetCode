class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp1;
        for (int i = 0; i < m; i++) {
            // if(nums1[i] != 0){
            temp1.push_back(nums1[i]);
            // }
        }
        vector<int> temp2;
        for (int i = 0; i < n; i++) {
            // if(nums2[i] != 0){
            temp2.push_back(nums2[i]);
            // }
        }
        for (int i = 0; i < temp2.size(); i++) {
            temp1.push_back(temp2[i]);
        }
        sort(temp1.begin(), temp1.end());
        nums1.clear();
        for (int i = 0; i < temp1.size(); i++) {
            nums1.push_back(temp1[i]);
        }
    }
};