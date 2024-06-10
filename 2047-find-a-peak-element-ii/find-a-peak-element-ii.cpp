class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rowmax = mat.size() - 1;
        int colmax = mat[0].size() - 1;
        int colmin = 0;
        int row = 0;

        while (colmax >= colmin) {
            int mid = (colmin + colmax) / 2;
            int max = mat[0][mid];
            row = 0;
            for (int i = 1; i <= rowmax; i++) {
                if (mat[i][mid] > max) {
                    max = mat[i][mid];
                    row = i;
                }
            }
            if ((mid == 0 || max > mat[row][mid - 1]) &&
                (mid == colmax || max > mat[row][mid + 1])) {
                return {row, mid};
            } else if (mid > 0 && max < mat[row][mid - 1]) {
                colmax = mid - 1;
            } else if (mid < colmax && max < mat[row][mid + 1]) {
                colmin = mid + 1;
            }
        }
        return {-1, -1};
    }
};