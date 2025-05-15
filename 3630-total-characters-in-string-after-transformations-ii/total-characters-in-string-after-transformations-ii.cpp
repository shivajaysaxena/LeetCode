typedef long long ll;
class Solution {
public:
    ll mod = 1e9 + 7;
    vector<vector<ll>> multiply(vector<vector<ll>> &a, vector<vector<ll>> &b) {
        int m = a.size(), x = a[0].size(), n = b[0].size();
        vector<vector<ll>> result(m, vector<ll>(n, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < x; k++)
                    result[i][j] = (result[i][j] + a[i][k] * b[k][j] % mod) % mod;
        return result;
    }

    vector<vector<ll>> matrixExponentiation(vector<vector<ll>> &matrix, ll t) {
        int size = matrix.size();
        vector<vector<ll>> result(26, vector<ll>(26, 0));
        for (int i = 0; i < 26; i++) result[i][i] = 1;
        while (t) {
            if (t % 2) {
                result = multiply(result, matrix);
            }
            matrix = multiply(matrix, matrix);
            t /= 2;
        }
        return result;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<vector<ll>> transformMatrix(26, vector<ll>(26, 0));
        for (int i = 0; i < 26; i++) {
            for (int j = 1; j <= nums[i]; j++) {
                transformMatrix[i][(i + j) % 26] += 1;
            }
        }
        vector<vector<ll>> matrix = matrixExponentiation(transformMatrix, t);
        vector<vector<ll>> cnt(1, vector<ll>(26, 0));
        for (auto &x: s) cnt[0][x - 'a'] += 1;
        vector<vector<ll>> result = multiply(cnt, matrix);
        ll ans = 0;
        for (auto &x: result[0]) ans = (ans + x) % mod;
        return ans;
    }
};