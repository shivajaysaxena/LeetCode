#define mod 1000000007;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto it : roads) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back(make_pair(v, wt));
            adj[v].push_back(make_pair(u, wt));
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;
        vector<long long> w(n, 0);
        vector<long long> dis(n, 1e14);

        w[0] = 1;
        dis[0] = 0;
        pq.push(make_pair(0, 0));

        while (pq.size() > 0) {
            auto frnt = pq.top();
            pq.pop();
            int node = frnt.second;
            long long d = frnt.first;

            for (auto it : adj[node]) {
                if (it.second + d < dis[it.first]) {
                    dis[it.first] = it.second + d;
                    w[it.first] = w[node] % mod;
                    pq.push(make_pair(it.second + d, it.first));
                } else if (it.second + d == dis[it.first]) {
                    w[it.first] += w[node] % mod;
                }
            }
        }
        return w[n - 1] % mod;
    }
};