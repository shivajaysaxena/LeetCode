class Solution {
public:
    int mini(int row, int rowEnd, int col, int colEnd,
             vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int minRow = n;
        int maxRow = -1;
        int minCol = m;
        int maxCol = -1;

        for (int i = row; i < rowEnd; i++) {
            for (int j = col; j < colEnd; j++) {
                if (grid[i][j] == 1) {
                    minCol = min(minCol, j);
                    maxCol = max(maxCol, j);
                    minRow = min(minRow, i);
                    maxRow = max(maxRow, i);
                }
            }
        }
        int l = maxRow - minRow + 1;
        int b = maxCol - minCol + 1;
        return l * b;
    }

    int utility(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int result = INT_MAX;

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                int top = mini(0, i, 0, m, grid);
                int bottomLeft = mini(i, n, 0, j, grid);
                int bottomRight = mini(i, n, j, m, grid);

                result = min(result, top + bottomLeft + bottomRight);

                int topLeft = mini(0, i, 0, j, grid);
                int topRight = mini(0, i, j, m, grid);
                int bottom = mini(i, n, 0, m, grid);

                result = min(result, topLeft + topRight + bottom);
            }
        }

        for (int r1 = 1; r1 < n; r1++) {
            for (int r2 = r1 + 1; r2 < n; r2++) {
                int top = mini(0, r1, 0, m, grid);
                int mid = mini(r1, r2, 0, m, grid);
                int bottom = mini(r2, n, 0, m, grid);

                result = min(result, top + mid + bottom);
            }
        }

        return result;
    }

    vector<vector<int>> rotateClockwise(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> rotated(m, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                rotated[j][n - i - 1] = grid[i][j];
            }
        }
        return rotated;
    }

    int minimumSum(vector<vector<int>>& grid) {
        int result = utility(grid);

        vector<vector<int>> rotatedGrid = rotateClockwise(grid);

        result = min(result, utility(rotatedGrid));

        return result;
    }
};