class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        long N = beans.size(), ans = LLONG_MAX,
             sum = accumulate(beans.begin(), beans.end(), 0L);
        sort(beans.begin(), beans.end());
        for (int i = 0; i < N; ++i) {
            ans = min(ans, sum - (N - i) * beans[i]);
        }
        return ans;
    }
};