class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n = grid.size();
        int m = grid[0].size();
        int k = queries.size();

        vector<pair<int, int>> q;
        for (int i = 0; i < k; i++) {
            q.push_back({queries[i], i});
        }
        sort(q.begin(), q.end());

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;
        vector<int> res(k);
        int maxPoints = 0;

        pq.push({grid[0][0], 0, 0});
        vis[0][0] = true;

        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for (int i = 0; i < k; i++) {
            int val = q[i].first, indx = q[i].second;
            while (!pq.empty() && pq.top()[0] < val) {
                auto curr = pq.top();
                pq.pop();
                int row = curr[1], col = curr[2];
                maxPoints++;

                for (auto& dir : directions) {
                    int newRow = row + dir[0], newCol = col + dir[1];
                    if (newRow >= 0 && newCol >= 0 && newRow < n &&
                        newCol < m && !vis[newRow][newCol]) {
                        pq.push({grid[newRow][newCol], newRow, newCol});
                        vis[newRow][newCol] = true;
                    }
                }
            }
            res[indx] = maxPoints;
        }
        return res;
    }
};