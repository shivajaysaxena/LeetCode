class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,
                                        int cStart) {
        int m = rows;
        int n = cols;
        vector<vector<int>> ans;
        vector<vector<int>> vis(m + n, vector<int>(m + n, 0));
        int x = rStart;
        int y = cStart;
        int k = 1;
        while (ans.size() < m * n) {
            for (int j = y; j < y + k; j++) {
                if (x >= 0 && j >= 0 && x < m && j < n && !vis[x][j]) {
                    vis[x][j] = 1;
                    ans.push_back({x, j});
                }
            }
            y += k;
            for (int i = x; i < x + k; i++) {
                if (i >= 0 && y >= 0 && i < m && y < n && !vis[i][y]) {
                    vis[i][y] = 1;
                    ans.push_back({i, y});
                }
            }
            x += k;
            k++;
            for (int j = y; j >= y - k; j--) {
                if (x >= 0 && j >= 0 && x < m && j < n && !vis[x][j]) {
                    vis[x][j] = 1;
                    ans.push_back({x, j});
                }
            }
            y -= k;
            for (int i = x; i >= x - k; i--) {
                if (i >= 0 && y >= 0 && i < m && y < n && !vis[i][y]) {
                    vis[i][y] = 1;
                    ans.push_back({i, y});
                }
            }
            x -= k;
            k++;
        }
        return ans;
    }
};