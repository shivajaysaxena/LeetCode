class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), start = 0, end = nums[n - 1] - nums[0];
        while (start < end) {
            int mid = (start + end) / 2, k = 0;
            for (int i = 1; i < n && k < p; i++) {
                if (nums[i] - nums[i - 1] <= mid) {
                    k++;
                    i++;
                }
            }
            if (k >= p) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }
};