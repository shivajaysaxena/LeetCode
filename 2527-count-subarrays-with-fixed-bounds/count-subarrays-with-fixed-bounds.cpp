class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long int mn = 0, mx = 0;
        long long int st = 0, st1 = 0, st2 = 0;
        long long int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < minK || nums[i] > maxK) {
                mn = mx = 0;
                st = i + 1;
            }
            if (nums[i] == minK) {
                mn = 1;
                st1 = i;
            }
            if (nums[i] == maxK) {
                mx = 1;
                st2 = i;
            }

            if (mn && mx)
                ans += min(st1, st2) - st + 1;
        }
        return ans;
    }
};