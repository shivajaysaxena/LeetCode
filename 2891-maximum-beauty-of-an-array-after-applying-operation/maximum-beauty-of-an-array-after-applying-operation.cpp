class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int start = 0;
        int maxCnt = 0;
        for (int i = 0; i < n; i++) {
            while (nums[start] + 2 * k < nums[i] && start < i) {
                start++;
            }
            maxCnt = max(maxCnt, i - start + 1);
        }
        return maxCnt;
    }
};