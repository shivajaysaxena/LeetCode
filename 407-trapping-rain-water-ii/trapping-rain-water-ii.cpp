class Solution {
public:
    int directions[5] = {0, 1, 0, -1, 0};
    int trapRainWater(vector<vector<int>>& heightMap) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            min_heap;
        int m = heightMap[0].size();
        int n = heightMap.size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            min_heap.push({heightMap[i][0], i, 0});
            min_heap.push({heightMap[i][m - 1], i, m - 1});
            visited[i][0] = true, visited[i][m - 1] = true;
        }
        for (int i = 0; i < m; i++) {
            min_heap.push({heightMap[0][i], 0, i});
            min_heap.push({heightMap[n - 1][i], n - 1, i});
            visited[0][i] = true, visited[n - 1][i] = true;
        }
        int ans = 0;
        while (!min_heap.empty()) {
            vector<int> values = min_heap.top();
            min_heap.pop();
            int h = values[0], row = values[1], col = values[2];
            for (int dir = 1; dir < 5; dir++) {
                int newRow = row + directions[dir - 1];
                int newCol = col + directions[dir];
                if (newRow >= 0 && newCol >= 0 && newRow < n && newCol < m &&
                    !visited[newRow][newCol]) {
                    visited[newRow][newCol] = true;
                    ans += max(0, h - heightMap[newRow][newCol]);
                    min_heap.push(
                        {max(h, heightMap[newRow][newCol]), newRow, newCol});
                }
            }
        }
        return ans;
    }
};