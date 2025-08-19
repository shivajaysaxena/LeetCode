class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        nums.push_back(1);
        const int s = nums.size();
        int a_len = 0;
        long long sum = 0;
        for (int i = 0; i < s; i++) {
            if (nums[i] == 0) {
                a_len++;
            } else if (a_len) {
                sum += (long long)a_len * (a_len + 1) / 2;
                a_len = 0;
            }
        }
        return sum;
    }
};