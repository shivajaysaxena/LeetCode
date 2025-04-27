class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int start = 0;
        int end = 2;
        int count = 0;
        if (2 * (nums[start] + nums[end]) == nums[1]) {
            count++;
        }
        start++;
        end++;
        while (end < nums.size()) {
            if (2 * (nums[start] + nums[end]) == nums[start + 1]) {
                count++;
            }
            start++;
            end++;
        }
        return count;
    }
};