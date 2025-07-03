class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> dp(n, -1);
        for (int i = 0; i < n; i++) {
            dp[i] = matrix[0][i];
        }
        for (int i = 1; i < n; i++) {
            vector<int> temp(n);
            for (int j = 0; j < n; j++) {
                if (j == 0) {
                    int a = dp[j] + matrix[i][j];
                    int b = dp[j + 1] + matrix[i][j];
                    temp[j] = min(a, b);
                } else if (j == n - 1) {
                    int a = dp[j] + matrix[i][j];
                    int b = dp[j - 1] + matrix[i][j];
                    temp[j] = min(a, b);
                } else {
                    int a = dp[j] + matrix[i][j];
                    int b = dp[j - 1] + matrix[i][j];
                    int c = dp[j + 1] + matrix[i][j];
                    temp[j] = min(a, min(b, c));
                }
            }
            dp = temp;
        }
        int ans = *min_element(dp.begin(), dp.end());
        return ans;
    }
};