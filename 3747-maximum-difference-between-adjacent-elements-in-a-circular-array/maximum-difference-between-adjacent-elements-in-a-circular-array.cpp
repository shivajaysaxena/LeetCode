class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        int maxi = 0;
        for (int i = 0; i < n; ++i) {
            int next = (i + 1) % n; 
            int diff = abs(nums[i] - nums[next]);
            maxi = max(maxi, diff);
        }
        return maxi;
    }
};
