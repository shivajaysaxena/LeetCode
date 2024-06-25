class Solution {
public:
    int findPoisonedDuration(vector<int>& ts, int d) {
        int n = ts.size(), ans = 0;
        for (int i = 0; i < n - 1; i++)
            (ts[i + 1] <= ts[i] + d - 1) ? ans += ts[i + 1] - ts[i] : ans += d;
        return ans + d;
    }
};