class Solution {
public:
    bool f(long long mid, vector<int>& ranks, int n) {
        long long ans = 0;
        for (int i = 0; i < ranks.size(); i++) {
            ans += sqrt(mid / ranks[i]);
        }
        return ans >= n;
    }
    long long repairCars(vector<int>& ranks, int n) {
        long long lo = 1;
        long long hi = 1e16;
        long long result = 0;
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            if (f(mid, ranks, n)) {
                result = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return result;
    }
};