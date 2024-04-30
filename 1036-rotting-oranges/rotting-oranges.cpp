class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int t = 0;
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                } else {
                    vis[i][j] = 0;
                }
            }
        }
        int delRow[4] = {1, 0, -1, 0};
        int delCol[4] = {0, 1, 0, -1};
        while (!q.empty()) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int tm = q.front().second;
            t = max(tm, t);
            q.pop();
            for (int k = 0; k < 4; k++) {
                int nRow = i + delRow[k];
                int nCol = j + delCol[k];
                if (nRow >= 0 && nCol >= 0 && nRow < m && nCol < n &&
                    vis[nRow][nCol] == 0 && grid[nRow][nCol] == 1) {
                    q.push({{nRow, nCol}, tm + 1});
                    vis[nRow][nCol] = 2;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] == 0 && grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return t;
    }
};