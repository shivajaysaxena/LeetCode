class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        long long
         n = nums.size();
        if (n < k) return -1;

        long long
         low = 0, high = 0;
        for (auto i: nums) {
            low = max(low, 1ll*i);
            high += i;
        }

        long long res = -1;
        while (low <= high) {
            long long mid = low + (high - low)/2;
            long long cnt = 1;
            long long sum = 0;

            for (auto i: nums) {
                if (sum + i <= mid) sum += i;
                else {
                    sum = i;
                    cnt ++;
                }
            }

            if (cnt > k) low = mid + 1;
            else {
                res = mid;
                high = mid - 1;
            }
        }

        return res;
    }
};