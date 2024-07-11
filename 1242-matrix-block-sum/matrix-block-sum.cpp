class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> A(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                A[i][j] = mat[i][j];
                if (i >= 1) {
                    A[i][j] += A[i - 1][j];
                }
                if (j >= 1) {
                    A[i][j] += A[i][j - 1];
                }
                if (i >= 1 && j >= 1) {
                    A[i][j] -= A[i - 1][j - 1];
                }
            }
        }
        vector<vector<int>> answer(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int r = min(i + k, m - 1);
                int c = min(j + k, n - 1);
                answer[i][j] = A[r][c];

                if (j - k - 1 >= 0) {
                    answer[i][j] -= A[r][j - k - 1];
                }
                if (i - k - 1 >= 0) {
                    answer[i][j] -= A[i - k - 1][c];
                }
                if (i - k - 1 >= 0 && j - k - 1 >= 0) {
                    answer[i][j] += A[i - k - 1][j - k - 1];
                }
            }
        }

        return answer;
    }
};