class Solution {
public:
    void makeset(int& a, vector<int>& p, vector<int>& s) {
        p[a] = a;
        s[a] = 1;
    }
    int find1(int u, vector<int>& p) {
        if (p[u] == u)
            return u;
        return p[u] = find1(p[u], p);
    }
    void union1(int u, int v, vector<int>& p, vector<int>& s) {
        int a = find1(u, p);
        int b = find1(v, p);
        if (a != b) {
            if (s[a] < s[b])
                swap(a, b);
            p[b] = a;
            s[a] += s[b];
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        int n, m = grid.size(), i, j, ans = 1, k = 0;
        n = m + 1;
        vector<int> p(n * n + 1), s(n * n + 1);
        for (i = 0; i <= n * n; i++) {
            makeset(k, p, s);
            k++;
        }
        k = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (i == 0 || j == 0 || i == n - 1 || j == n - 1) {
                    union1(k, 0, p, s);
                }
                k++;
            }
        }
        for (i = 0; i < m; i++) {
            for (j = 0; j < m; j++) {
                if (grid[i][j] == '/') {
                    if (find1((i + 1) * n + j, p) == find1(i * n + j + 1, p)) {
                        ans++;
                    }
                    union1((i + 1) * n + j, i * n + j + 1, p, s);
                } else if (grid[i][j] == '\\') {
                    if (find1((i)*n + j, p) == find1((i + 1) * n + j + 1, p)) {
                        ans++;
                    }
                    union1((i)*n + j, (i + 1) * n + j + 1, p, s);
                }
            }
        }
        return ans;
    }
};