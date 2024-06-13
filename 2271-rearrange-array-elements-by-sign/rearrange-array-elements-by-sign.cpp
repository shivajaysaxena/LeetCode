class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        int ve = 0;
        int ne = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                ans[ve] = nums[i];
                ve += 2;
            } else {
                ans[ne] = nums[i];
                ne += 2;
            }
        }
        return ans;
    }
};