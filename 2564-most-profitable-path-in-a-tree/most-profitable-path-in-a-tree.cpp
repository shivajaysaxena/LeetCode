class Solution {
    vector<int> path;
    bool dfs(int node, int pa, vector<vector<int>>& adj, int d) {
        if (node == 0) {
            return true;
        }
        bool f = 0;
        for (auto i : adj[node]) {
            if (i != pa && path[i] == -1) {
                path[i] = d;
                if (dfs(i, node, adj, d + 1))
                    return true;
                path[i] = -1;
            }
        }
        return 0;
    }
    int solve(int node, int pa, vector<vector<int>>& adj, int d,
              vector<int>& amount) {
        int maxi = INT_MIN;
        int x = 0;
        if (path[node] == -1 || path[node] > d)
            x += amount[node];
        else if (path[node] == d)
            x += amount[node] / 2;
        for (auto i : adj[node]) {
            if (i != pa) {
                maxi = max(maxi, solve(i, node, adj, d + 1, amount) + x);
            }
        }
        if (maxi == INT_MIN)
            return x;
        return maxi;
    }

public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob,
                           vector<int>& amount) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        for (auto i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        path.resize(n, -1);
        path[bob] = 0;
        dfs(bob, -1, adj, 1);
        int ans = solve(0, -1, adj, 0, amount);
        return ans;
    }
};