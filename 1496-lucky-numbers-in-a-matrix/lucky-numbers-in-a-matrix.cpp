class Solution {
public:
    bool RowCheck(int element, vector<vector<int>>& matrix, int x) {
        int mini = INT_MAX;
        for (int i = 0; i < matrix[x].size(); i++) {
            if (matrix[x][i] < mini) {
                mini = matrix[x][i];
            }
        }
        return (element == mini) ? true : false;
    }
    bool ColCheck(int element, vector<vector<int>>& matrix, int y) {
        int maxi = INT_MIN;
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][y] > maxi) {
                maxi = matrix[i][y];
            }
        }
        return (element == maxi) ? true : false;
    }

    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> Res;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (RowCheck(matrix[i][j], matrix, i) &&
                    ColCheck(matrix[i][j], matrix, j)) {
                    Res.push_back(matrix[i][j]);
                }
            }
        }
        return Res;
    }
};