class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> L(n);
        for (int i = 0; i < n; i++) {
            L[i] = -1;
        }
        vector<bool> vis(n, false);
        queue<int> Q;

        for (int o = 0; o < n; o++) {
            if (vis[o] == false) {
                Q.push(o);
                while (!Q.empty()) {
                    int u = Q.front();
                    Q.pop();
                    for (int v : graph[u]) {
                        if (L[v] < 0) {
                            Q.push(v);
                            L[v] = L[u] + 1;
                        }
                    }
                }
            }
        }
        bool ans = false;

        int u, c;
        bool brkchk = false;
        for (u = 0; u < n; u++) {
            c = 0;
            for (int v : graph[u]) {
                if (L[u] % 2 == L[v] % 2) {
                    brkchk = true;
                    break;
                }
                if (brkchk == true) {
                    break;
                }
                c++;
            }
        }
        if (u == n && c == graph[n - 1].size()) {
            ans = true;
        } else {
            ans = false;
        }
        return ans;
    }
};