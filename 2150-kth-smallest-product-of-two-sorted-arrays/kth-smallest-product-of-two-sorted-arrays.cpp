class Solution {
public:
    long long f(vector<int>& v1, vector<int>& v2, long long k, long long t) {
        long long ct = 0;
        for (long long i = 0; i < v1.size(); i++) {
            if (v1[i] == 0) {
                if (t >= 0)
                    ct += v2.size();
            } else if (v1[i] > 0) {
                long long val = floor((double)t / v1[i]);
                auto it = upper_bound(v2.begin(), v2.end(), val);
                if (it == v2.end() || (*it) > val)
                    it--;
                ct += (it - v2.begin() + 1);
            } else {
                long long val = ceil((double)t / v1[i]);
                auto it = lower_bound(v2.begin(), v2.end(), val);
                ct += (v2.end() - it);
            }
            if (ct > k)
                return ct;
        }
        return ct;
    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2,
                                 long long k) {
        long long low = min({nums1[0] * 1LL * nums2.back(),
                             nums1.back() * 1LL * nums2[0],
                             nums1[0] * 1LL * nums2[0]}),
                  high = max({nums1[0] * 1LL * nums2[0],
                              nums1.back() * 1LL * nums2.back(),
                              nums1[0] * 1LL * nums2.back(),
                              nums2[0] * 1LL * nums1.back()}),
                  ans = 0;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long x = f(nums1, nums2, k, mid);
            if (x < k) {
                low = mid + 1;
            } else {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};