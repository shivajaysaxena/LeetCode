class Solution {
public:
    int dx[4]{1, -1, 0, 0}, dy[4]{0, 0, 1, -1};
    int dfs(int i, int j, vector<vector<int>>& grid) {
        int ret = grid[i][j];
        grid[i][j] = 0;

        for (int k = 0; k < 4; k++) {
            int a = i + dx[k], b = j + dy[k];
            if (min(a, b) >= 0 && a < grid.size() && b < grid[0].size() &&
                grid[a][b])
                ret += dfs(a, b, grid);
        }
        return ret;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j])
                    ans = max(ans, dfs(i, j, grid));

        return ans;
    }
};