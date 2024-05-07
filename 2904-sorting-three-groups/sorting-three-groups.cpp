class Solution {

    int fun(int i, int j, vector<int>& nums) {
        int count = 0;

        for (int x = 0; x < i; x++)
            if (nums[x] != 1)
                count++;

        for (int x = i; x < j; x++)
            if (nums[x] != 2)
                count++;

        for (int x = j; x < nums.size(); x++)
            if (nums[x] != 3)
                count++;

        return count;
    }

public:
    int minimumOperations(vector<int>& nums) {

        int ans = INT_MAX;
        int n = nums.size();

        if (n == 1)
            return 0;

        for (int i = 0; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                ans = min(ans, fun(i, j, nums));
            }
        }

        return ans;
    }
};
