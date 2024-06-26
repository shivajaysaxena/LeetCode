class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int c = INT_MAX;
        int s = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] > c)
                return true;
            if (s < nums[i]) {
                c = min(c, nums[i]);
            }
            s = min(s, nums[i]);
        }
        return false;
    }
};