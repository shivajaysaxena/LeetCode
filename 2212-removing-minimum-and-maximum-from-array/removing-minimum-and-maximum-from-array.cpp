class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mn = INT_MAX, mx = INT_MIN;
        int a, b;
        int s = nums.size();
        for (int i = 0; i < s; i++) {
            if (mn > nums[i]) {
                mn = nums[i];
                a = i;
            }
            if (mx < nums[i]) {
                mx = nums[i];
                b = i;
            }
        }
        int j = max(a, b) + 1;
        int k = s - min(a, b);
        return min(min(j, k), min(a, b) + 1 + s - max(a, b));
    }
};