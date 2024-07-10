class Solution {
public:
    int numTilings(int n) {
        int md = 1e9;
        md += 7;
        vector<long long> ans(1001, 0);
        ans[1] = 1;
        ans[2] = 2;
        ans[3] = 5;
        if (n < 4) {
            return ans[n];
        }
        for (int i = 4; i <= n; i++) {
            ans[i] = 2 * ans[i - 1] + ans[i - 3];
            ans[i] = ans[i] % md;
        }
        return ans[n];
    }
};