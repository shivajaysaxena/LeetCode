#define ll long long
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<ll>> pfx(m, vector<ll>(n + 1, 1));
        vector<vector<ll>> sfx(m, vector<ll>(n + 1, 1));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j)
                pfx[i][j + 1] = (pfx[i][j] * grid[i][j]) % 12345;
            for (int j = n - 1; j >= 0; --j)
                sfx[i][j] = (sfx[i][j + 1] * grid[i][j]) % 12345;
        }
        vector<ll> pfxr(m + 1, 1), sfxr(m + 1, 1);
        for (int i = 0, j = m - 1; i < m; ++i, --j) {
            pfxr[i + 1] = (pfxr[i] * sfx[i][0]) % 12345;
            sfxr[j] = (sfxr[j + 1] * sfx[j][0]) % 12345;
        }

        vector<vector<int>> ans(m, vector<int>(n, 1));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[i][j] = (ans[i][j] * pfxr[i]) % 12345;
                ans[i][j] = (ans[i][j] * sfxr[i + 1]) % 12345;
                ans[i][j] = (ans[i][j] * pfx[i][j]) % 12345;
                ans[i][j] = (ans[i][j] * sfx[i][j + 1]) % 12345;
            }
        }
        return ans;
    }
};