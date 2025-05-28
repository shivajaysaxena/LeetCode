class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        auto g1 = build_graph(edges1, n);
        auto g2 = build_graph(edges2, m);
        if (k == 0)
            return vector<int>(n, 1);
        auto cnt1 = bfs_count_nodes(g1, k);
        auto cnt2 = bfs_count_nodes(g2, k - 1);
        int best2 = 0;
        for (int x : cnt2)
            best2 = max(best2, x);
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
            ans[i] = cnt1[i] + best2;
        return ans;
    }

private:
    vector<vector<int>> build_graph(const vector<vector<int>>& edges, int sz) {
        vector<vector<int>> g(sz);
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        return g;
    }
    vector<int> bfs_count_nodes(const vector<vector<int>>& g, int K) {
        int N = g.size();
        vector<int> result(N), visited(N);
        int stamp = 1;
        vector<int> q;
        q.reserve(N);

        for (int start = 0; start < N; ++start, ++stamp) {
            if (K < 0) {
                result[start] = 1;
                continue;
            }
            q.clear();
            q.push_back(start);
            visited[start] = stamp;
            int head = 0, tail = 1;
            int level = 0, count = 1;
            while (head < tail && level < K) {
                int sz = tail - head;
                while (sz--) {
                    int u = q[head++];
                    for (int v : g[u]) {
                        if (visited[v] != stamp) {
                            visited[v] = stamp;
                            q.push_back(v);
                            ++tail;
                            ++count;
                        }
                    }
                }
                ++level;
            }
            result[start] = count;
        }
        return result;
    }
};