class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int mx_or = 0, n = nums.size();
        for (int x : nums)
            mx_or |= x;

        int total_subsets = pow(2, n) - 1;

        int cnt = 1;
        for (int i = 1; i < total_subsets; i++) {
            int or_sub = 0;
            for (int j = 0; j < n; j++) {
                int x = 1 << j;
                if (x & i)
                    or_sub |= nums[j];
            }
            if (or_sub == mx_or)
                ++cnt;
        }

        return cnt;
    }
};