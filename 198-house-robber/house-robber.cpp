class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int temp1 = nums[0], temp2 = 0;

        for (int i = 1; i < n; i++) {
            int take = nums[i] + temp2;
            int ntake = 0 + temp1;
            temp2 = temp1;
            temp1 = max(take, ntake);
        }
        return temp1;
    }
};