class Solution {
public:
    bool isvalid(vector<vector<char>>& board, char ch, int i, int j) {
        for (int k = 0; k < 9; k++) {
            if (board[i][k] == ch && k != j)
                return false;
            if (board[k][j] == ch && k != i)
                return false;
        }
        int row = (i / 3) * 3;
        int col = (j / 3) * 3;
        for (int s = row; s < row + 3; s++) {
            for (int t = col; t < col + 3; t++) {
                if (board[s][t] == ch && s != i && t != j)
                    return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (!isvalid(board, board[i][j], i, j))
                        return false;
                }
            }
        }
        return true;
    }
};