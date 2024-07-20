class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum,
                                      vector<int>& colSum) {
        int n = rowSum.size();
        int m = colSum.size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int mini = min(rowSum[i], colSum[j]);
                rowSum[i] -= mini;
                colSum[j] -= mini;
                ans[i][j] = mini;
            }
        }
        return ans;
    }
};