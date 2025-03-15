class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());
        int result = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int housesToRob = 0;

            for (int i = 0; i < n; i++) {
                if (nums[i] <= mid) {
                    housesToRob++;
                    i++;
                }
            }

            if (housesToRob >= k) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }
};