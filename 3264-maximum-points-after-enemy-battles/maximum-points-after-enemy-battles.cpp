class Solution {
public:
    long long maximumPoints(vector<int>& e, int curr) {
        int n = e.size();
        sort(e.begin(), e.end());
        if (curr < e[0]) {
            return 0;
        }
        long long tot = curr;

        for (int i = 0; i < n; i++) {
            tot += e[i];
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            long long x = tot / e[i];
            tot -= (x * e[i]);
            ans += x;
        }

        return ans - 1;
    }
};