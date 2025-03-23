class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int> nums) {
        int n = nums.size();
        if (n == 0)
            return {};

        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1), parent(n, -1);
        int maxSize = 1, maxIndex = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j; 
                }
            }

            if (dp[i] > maxSize) {
                maxSize = dp[i];
                maxIndex = i;
            }
        }

        
        vector<int> result;
        for (int i = maxIndex; i != -1; i = parent[i]) {
            result.push_back(nums[i]);
        }

        reverse(result.begin(), result.end()); 
        return result;
    }
};
