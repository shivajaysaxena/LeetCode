class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) { solve(board); }

private:
    // Recursive method to solve the Sudoku
    bool solve(vector<vector<char>>& board) {
        // Size of the board
        int n = 9;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Empty cell found
                if (board[i][j] == '.') {
                    for (char digit = '1'; digit <= '9'; digit++) {
                        // Check if digit can be placed
                        if (areRulesMet(board, i, j, digit)) {
                            // Place digit
                            board[i][j] = digit;
                            // Recur to place next digits
                            if (solve(board)) {
                                return true;
                            } else {
                                // Reset if placing digit doesn't solve Sudoku
                                board[i][j] = '.';
                            }
                        }
                    }
                    // If no digit can be placed, return false
                    return false;
                }
            }
        }
        return true; // Sudoku solved
    }

    // Method to check if placing a digit follows Sudoku rules
    bool areRulesMet(vector<vector<char>>& board, int row, int col,
                     char digit) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == digit || board[i][col] == digit) {
                // Digit already in row or column
                return false;
            }
        }
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == digit) {
                    // Digit already in 3x3 sub-box
                    return false;
                }
            }
        }
        // Digit can be placed
        return true;
    }
};