class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0] - 1].push_back(e[1] - 1);
            adj[e[1] - 1].push_back(e[0] - 1);
        }
        vector<int> color(n, -1);
        vector<vector<int>> components;
        for (int i = {0}; i < n; ++i) {
            if (color[i] == -1) {
                components.emplace_back();
                if (!dfs(i, 0, adj, color, components.back())) return -1;
            }
        }
        int maxGroups = {0};
        for (const auto& comp : components) {
            maxGroups += bfsMaxDepth(comp, adj);
        }
        return maxGroups;
    }
private:
    bool dfs(int node, int col, const vector<vector<int>>& adj, vector<int>& color, vector<int>& comp) {
        color[node] = col;
        comp.push_back(node);
        for (int neighbor : adj[node]) {
            if (color[neighbor] == col) return false;
            if (color[neighbor] == -1 && !dfs(neighbor, 1 - col, adj, color, comp)) return false;
        }
        return true;
    }
    int bfsMaxDepth(const vector<int>& comp, const vector<vector<int>>& adj) {
        int maxDepth = {0};
        for (int start : comp) {
            vector<int> depth(adj.size(), -1);
            vector<int> queue = {start};
            depth[start] = {0};
            for (size_t i = {0}; i < queue.size(); ++i) {
                int node = queue[i];
                for (int neighbor : adj[node]) {
                    if (depth[neighbor] == -1) {
                        depth[neighbor] = depth[node] + 1;
                        queue.push_back(neighbor);
                    }
                }
            }
            maxDepth = max(maxDepth, *max_element(depth.begin(), depth.end()));
        }
        return maxDepth + 1;
    }
};