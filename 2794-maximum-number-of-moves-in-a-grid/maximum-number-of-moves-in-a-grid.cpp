class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        for (int j = cols - 2; j >= 0; j--) {
            for (int i = 0; i < rows; i++) {
                int ans = 0;
                if (i + 1 < rows && grid[i][j] < grid[i + 1][j + 1]) {
                    ans = max(ans, 1 + dp[i + 1][j + 1]);
                }
                if (grid[i][j] < grid[i][j + 1]) {
                    ans = max(ans, 1 + dp[i][j + 1]);
                }
                if (i - 1 >= 0 && grid[i][j] < grid[i - 1][j + 1]) {
                    ans = max(ans, 1 + dp[i - 1][j + 1]);
                }
                dp[i][j] = ans;
            }
        }
        int ans = 0;
        for (int i = 0; i < rows; i++) {
            ans = max(ans, dp[i][0]);
        }
        return ans;
    }
};