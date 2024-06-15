class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int m = nums1.size();
        int n = nums2.size();
        for (int i = 0; i < m; i++) { 
            int x = find(nums2.begin(), nums2.end(), nums1[i]) - nums2.begin();
            int flag = 0;
            for (int j = x; j < n; j++) { 
                if (nums2[j] > nums1[i] && flag == 0) {
                    flag = 1;
                    ans.push_back(nums2[j]);
                }
            }
            if (flag == 0)
                ans.push_back(-1);
        }
        return ans;
    }
};