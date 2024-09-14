class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxElement = *max_element(nums.begin(), nums.end());
        int maxLen = 0, currentLen = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == maxElement) {
                currentLen++;
                maxLen = max(maxLen, currentLen);
            } else {
                maxLen = max(maxLen, currentLen);
                currentLen = 0;
            }
        }
        
        return maxLen;
    }
};