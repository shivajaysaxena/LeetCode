class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> degree(n, 0);
        vector<int> leaves;
        vector<vector<int>> adj_list(n);

        for (vector<int> edge : edges) {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }

        // loop through adjancy list to check for leaf nodes
        for (int i = 0; i < n; i++) {
            degree[i] = adj_list[i].size();
            if (degree[i] <= 1) {
                leaves.push_back(i);
                degree[i] = 0;
            }
        }

        int processedLeafs = leaves.size();

        while (processedLeafs < n) {
            vector<int> newLeaves;
            for (int node : leaves) {
                for (int nei : adj_list[node]) {
                    if (--degree[nei] == 1) {
                        newLeaves.push_back(nei);
                    }
                }
                degree[node] = 0;
            }
            processedLeafs += newLeaves.size();
            leaves = newLeaves;
        }
        return leaves;
    }
};