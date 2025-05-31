class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long curr = 1, maxn = INT_MIN, temp = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            curr = curr * nums[i];

            if (maxn < curr)
                maxn = curr;

            if (curr == 0)
                curr = 1;
        }

        curr = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            curr = curr * nums[i];

            if (temp < curr)
                temp = curr;

            if (curr == 0)
                curr = 1;
        }
        return max(maxn, temp);
    }
};