class Solution {
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        vector<vector<int>> adj(61);
        int n = targetGrid.size();
        int m = targetGrid[0].size();
        for (int c = 1; c <= 60; c++) {
            int mnr = n, mnc = m, mxr = 0, mxc = 0;
            for (int i = 0; i < targetGrid.size(); i++) {
                for (int j = 0; j < targetGrid[0].size(); j++) {
                    if (targetGrid[i][j] == c) {
                        if (i <= mnr) {
                            mnr = i;
                        }
                        if (i >= mxr) {
                            mxr = i;
                        }
                        if (j <= mnc) {
                            mnc = j;
                        }
                        if (j >= mxc) {
                            mxc = j;
                        }
                    }
                }
            }
            vector<int> vis(61, 0);
            for (int i = mnr; i <= mxr; i++) {
                for (int j = mnc; j <= mxc; j++) {
                    if (targetGrid[i][j] != c && vis[targetGrid[i][j]] == 0) {
                        vis[targetGrid[i][j]] = 1;
                        adj[targetGrid[i][j]].push_back(c);
                    }
                }
            }
        }
        vector<int> result;
        vector<int> indeg(61, 0);
        for (int i = 1; i <= 60; i++) {
            for (auto it : adj[i]) {
                indeg[it]++;
            }
        }
        queue<int> q;
        for (int i = 1; i < 61; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            result.push_back(top);
            for (auto it : adj[top]) {
                indeg[it]--;
                if (indeg[it] == 0)
                    q.push(it);
            }
        }
        if (result.size() == 60)
            return true;
        return false;
    }
};