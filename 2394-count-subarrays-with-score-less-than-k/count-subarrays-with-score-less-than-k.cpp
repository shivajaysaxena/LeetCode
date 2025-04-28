class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {

        int n = nums.size();
        int i = 0;
        long long sum = 0;
        long long cnt = 0;
        for (int j = 0; j < n; ++j) {
            sum += nums[j];
            while (i <= j && sum * (j - i + 1) >= k) {
                sum -= nums[i++];
            }
            cnt += (j - i + 1);
        }
        return cnt;
    }
};