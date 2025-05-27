class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& d : times) {
            int u = d[0];
            int v = d[1];
            int wt = d[2];
            adj[u].push_back({wt, v});
        }
        vector<int> dis(n + 1, INT_MAX);
        dis[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, k});
        while (!pq.empty()) {
            int node = pq.top().second;
            pq.pop();
            for (int i = 0; i < adj[node].size(); i++) {
                if (dis[adj[node][i].second] > dis[node] + adj[node][i].first) {
                    dis[adj[node][i].second] = dis[node] + adj[node][i].first;
                    pq.push({dis[adj[node][i].second], adj[node][i].second});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i < dis.size(); i++) {
            if (dis[i] == INT_MAX)
                return -1;
            ans = max(ans, dis[i]);
        }
        return ans;
    }
};