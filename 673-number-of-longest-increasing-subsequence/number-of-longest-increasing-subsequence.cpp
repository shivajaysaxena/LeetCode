class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;

        vector<int> length(n, 1), count(n, 1); 
        int maxLength = 1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) { 
                    if (length[j] + 1 > length[i]) {
                        length[i] = length[j] + 1;
                        count[i] = count[j]; 
                    } else if (length[j] + 1 == length[i]) {
                        count[i] += count[j]; 
                    }
                }
            }
            maxLength = max(maxLength, length[i]);
        }

        int result = 0;
        for (int i = 0; i < n; ++i) {
            if (length[i] == maxLength) {
                result += count[i];
            }
        }
        return result;
    }
};