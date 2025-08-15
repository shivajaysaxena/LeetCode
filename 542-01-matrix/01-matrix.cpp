class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        vector<vector<int>> dist(rows, vector<int>(cols, 0));
        vector<vector<int>> visited(rows, vector<int>(cols, 0));

        queue<pair<pair<int, int>, int>> bfsQueue;

        // Step 1: Enqueue all 0's
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (mat[r][c] == 0) {
                    bfsQueue.push({{r, c}, 0});
                    visited[r][c] = 1;
                }
            }
        }

        // Movement vectors (Up, Right, Down, Left)
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        // Step 2: Multi-source BFS
        while (!bfsQueue.empty()) {
            auto [cell, steps] = bfsQueue.front();
            int row = cell.first;
            int col = cell.second;
            bfsQueue.pop();

            dist[row][col] = steps;

            for (int i = 0; i < 4; i++) {
                int newRow = row + dx[i];
                int newCol = col + dy[i];

                // Check boundaries and if not visited
                if (newRow >= 0 && newRow < rows && newCol >= 0 &&
                    newCol < cols && visited[newRow][newCol] == 0) {
                    visited[newRow][newCol] = 1;
                    bfsQueue.push({{newRow, newCol}, steps + 1});
                }
            }
        }

        return dist;
    }
};