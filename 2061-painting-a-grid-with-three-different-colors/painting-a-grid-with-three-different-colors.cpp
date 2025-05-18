typedef long long ll;
class Solution {
public:
    void prepare(string& cur, int idx, vector<string>& arr, int len) {
        if (idx == len) {
            arr.push_back(cur);
            return;
        }
        for (char c = 'a'; c <= 'c'; c++) {
            if (idx != 0 && cur.back() == c)
                continue;
            cur.push_back(c);
            prepare(cur, idx + 1, arr, len);
            cur.pop_back();
        }
    }

    int colorTheGrid(int m, int n) {
        ll mod = 1e9 + 7;
        int type = 3 * pow(2, m - 1);

        vector<string> possible;
        string tmp = "";
        prepare(tmp, 0, possible, m);
        vector<vector<bool>> valid(type, vector<bool>(type, true));
        for (int i = 0; i < type; i++)
            for (int j = 0; j < type; j++)
                for (int k = 0; k < m; k++)
                    if (possible[i][k] == possible[j][k])
                        valid[i][j] = false;

        vector<vector<int>> f(n, vector<int>(type, 0));
        for (int i = 0; i < type; i++)
            f[0][i] = 1;
        for (int i = 1; i < n; i++)
            for (int prev = 0; prev < type; prev++)
                for (int cur = 0; cur < type; cur++)
                    if (valid[prev][cur])
                        f[i][cur] = (f[i][cur] + f[i - 1][prev]) % mod;
        ll ans = 0;
        for (auto& x : f[n - 1])
            ans = (ans + x) % mod;
        return ans;
    }
};