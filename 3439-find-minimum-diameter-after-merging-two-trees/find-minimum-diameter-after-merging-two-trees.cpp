class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        auto diameter = [](vector<vector<int>>& edges){
            int n = edges.size() + 1;
            vector<int> degree(n, 0);
            vector<vector<int>> adj(n);
            for (const auto& edge : edges){
                int v = edge[0], w = edge[1];
                adj[v].push_back(w);
                adj[w].push_back(v);
                degree[v]++;
                degree[w]++;
            }
            deque<int> q;
            for (int i = 0; i < n; i++){
                if (degree[i] == 1){
                    q.push_back(i);
                }
            }
            int level = 0, left = n;
            while (left > 2){
                int size_q = q.size();
                left -= size_q;
                for (int i = 0; i < size_q; i++){
                    int v = q.front();
                    q.pop_front();
                    for( int w : adj[v]){
                        degree[w]--;
                        if (degree[w] == 1){
                            q.push_back(w);
                        }
                    }
                }
                level++;
            }
            return left == 2 ? 2 * level + 1 : 2 * level;
        };
        int d1 = diameter(edges1);
        int d2 = diameter(edges2);
        return max({d1, d2, ((d1 + 1) / 2) + ((d2 + 1) / 2) + 1});
    }
};