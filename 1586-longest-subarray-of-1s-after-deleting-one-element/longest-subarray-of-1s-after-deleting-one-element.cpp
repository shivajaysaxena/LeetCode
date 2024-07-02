class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int first = 0, second = 0, ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                ans = max(ans, first + second);
                first = second;
                second = 0;
            } else
                second++;
        }
        ans = max(ans, first + second);

        if (ans == nums.size())
            return ans - 1;
        return ans;
    }
};