class Solution {
private:
    using ll = long long;
    const ll INF = 1e18;

    vector<vector<pair<int, ll>>> adj;
    vector<vector<int>>* edges_ptr;

    pair<vector<ll>, vector<int>> dijkstra(int source, bool skip_negative) {
        vector<ll> dist(adj.size(), INF);
        vector<int> parent(adj.size(), -1);
        dist[source] = 0;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
        pq.push({0, source});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node])
                continue;

            for (auto [nei, w] : adj[node]) {
                if (w == -1) {
                    if (skip_negative)
                        continue;
                    w = 1;
                }
                ll d2 = d + w;
                if (d2 < dist[nei]) {
                    dist[nei] = d2;
                    parent[nei] = node;
                    pq.push({d2, nei});
                }
            }
        }
        return {dist, parent};
    }

public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges,
                                           int source, int destination,
                                           int target) {
        adj.resize(n);
        edges_ptr = &edges;

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        auto [distR, parentR] = dijkstra(destination, true);
        if (distR[source] < target)
            return {};

        auto [dist, parent] = dijkstra(source, false);
        if (dist[destination] > target)
            return {};

        vector<int> path;
        for (int v = destination; v != -1; v = parent[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());

        unordered_map<ll, ll> edge_map;
        for (auto& edge : edges) {
            edge_map[min(edge[0], edge[1]) * (ll)n + max(edge[0], edge[1])] =
                edge[2];
        }

        ll walked = 0;
        for (int i = 0; i < path.size() - 1; ++i) {
            int u = path[i], v = path[i + 1];
            ll key = min(u, v) * (ll)n + max(u, v);
            if (edge_map[key] == -1) {
                edge_map[key] = max(target - distR[v] - walked, 1LL);
                if (edge_map[key] > 1)
                    break;
            }
            walked += edge_map[key];
        }

        for (auto& [key, w] : edge_map) {
            if (w == -1) {
                w = 2e9;
            }
        }

        for (auto& edge : edges) {
            ll key = min(edge[0], edge[1]) * (ll)n + max(edge[0], edge[1]);
            edge[2] = edge_map[key];
        }

        return edges;
    }
};