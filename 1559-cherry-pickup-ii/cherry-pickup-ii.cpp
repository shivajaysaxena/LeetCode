class Solution {
private:
    int func(int i, int j1, int j2, int n, int m, vector<vector<int>>& matrix,
             vector<vector<vector<int>>>& dp) {
        if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
            return -1e9;

        if (i == n - 1) {
            if (j1 == j2)
                return matrix[i][j1];
            else
                return matrix[i][j1] + matrix[i][j2];
        }
        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];

        int maxi = INT_MIN;
        for (int di = -1; di <= 1; di++) {
            for (int dj = -1; dj <= 1; dj++) {
                int ans;

                if (j1 == j2)
                    ans = matrix[i][j1] +
                          func(i + 1, j1 + di, j2 + dj, n, m, matrix, dp);
                else
                    ans = matrix[i][j1] + matrix[i][j2] +
                          func(i + 1, j1 + di, j2 + dj, n, m, matrix, dp);
                maxi = max(maxi, ans);
            }
        }
        return dp[i][j1][j2] = maxi;
    }

public:
    int cherryPickup(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(m, -1)));
        return func(0, 0, m - 1, n, m, matrix, dp);
    }
};