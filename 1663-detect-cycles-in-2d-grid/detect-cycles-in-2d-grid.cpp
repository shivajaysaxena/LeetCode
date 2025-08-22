class Solution {
private:
    bool isCycle(vector<vector<char>> &grid, vector<vector<int>> &visited, int startRow, int startCol) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, pair<int, int>>> q;
        q.push({{startRow, startCol}, {-1, -1}});
        visited[startRow][startCol] = 1;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int prow = q.front().second.first;
            int pcol = q.front().second.second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == grid[row][col]) {
                    if (!visited[nrow][ncol]) {
                        visited[nrow][ncol] = 1;
                        q.push({{nrow, ncol}, {row, col}});
                    } else if (nrow != prow || ncol != pcol) {
                        return true;  // Cycle found
                    }
                }
            }
        }
        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j]) {
                    if (isCycle(grid, visited, i, j)) return true;
                }
            }
        }

        return false;
    }
};