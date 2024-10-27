class Solution {
public:
    int dp[301][301];
    int rec(int i, int j, vector<vector<int>>& matrix) {
        if (i < 0 || j < 0 || matrix[i][j] == 0) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int n = matrix.size();
        int m = matrix[0].size();
        dp[i][j] = 1;
        if (i > 0 && j > 0) {
            dp[i][j] =
                1 + min(rec(i - 1, j, matrix),
                        min(rec(i, j - 1, matrix), rec(i - 1, j - 1, matrix)));
        }
        return dp[i][j];
    }
    int countSquares(vector<vector<int>>& matrix) {
        int i, j;
        int n = matrix.size();
        int m = matrix[0].size();
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                ans += rec(i, j, matrix);
            }
        }
        return ans;
    }
};