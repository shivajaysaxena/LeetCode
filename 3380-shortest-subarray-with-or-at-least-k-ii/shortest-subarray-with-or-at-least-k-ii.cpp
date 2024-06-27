class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        if (k == 0) {
            return 1;
        }
        int ans = nums.size() + 1;
        vector<int> bits(32);
        int l = 0;
        int n = nums.size();
        for (int r = 0; r < n; r++) {
            int temp = 0;
            for (int i = 0; i < 32; i++) {
                if (nums[r] & (1 << i))
                    bits[i]++;
                if (bits[i])
                    temp |= (1 << i);
            }
            if (temp >= k)
                ans = min(ans, r - l + 1);
            while (temp >= k) {
                temp = 0;
                for (int i = 0; i < 32; i++) {
                    if (nums[l] & (1 << i))
                        bits[i]--;
                    if (bits[i])
                        temp |= (1 << i);
                }
                l++;
                if (temp >= k) {
                    ans = min(ans, r - l + 1);
                }
            }
        }
        if (ans == (nums.size() + 1))
            return -1;
        return ans;
    }
};