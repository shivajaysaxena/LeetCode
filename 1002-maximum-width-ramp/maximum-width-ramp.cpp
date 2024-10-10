class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<int> minnum(n, 0);
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[minnum[i - 1]])
                minnum[i] = i;
            else {
                minnum[i] = minnum[i - 1];
                while (ans < i && nums[i] >= nums[minnum[i - ans - 1]])
                    ans = i - minnum[i - ans - 1];
            }
        }
        return ans;
    }
};