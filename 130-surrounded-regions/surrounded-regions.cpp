class Solution {
public:
    bool liesOnBorder(int curr_row, int curr_col, int m, int n) {
        return (curr_row == m - 1 || curr_col == n - 1 || curr_row == 0 ||
                curr_col == 0);
    }

    bool isValid(int r, int c, int m, int n) {
        return (r >= 0 && c >= 0 && r < m && c < n);
    }

    bool dfs(vector<vector<char>>& mat, vector<vector<int>>& vis, int curr_row,
             int curr_col, int m, int n, vector<pair<int, int>>& component) {
        vis[curr_row][curr_col] = 1;
        component.push_back({curr_row, curr_col});

        bool good = !liesOnBorder(curr_row, curr_col, m, n);

        int row[4] = {0, -1, 0, 1};
        int col[4] = {-1, 0, 1, 0};

        for (int i = 0; i < 4; i++) {
            int new_row = curr_row + row[i];
            int new_col = curr_col + col[i];
            if (isValid(new_row, new_col, m, n) &&
                mat[new_row][new_col] == 'O' && !vis[new_row][new_col]) {
                bool child_good =
                    dfs(mat, vis, new_row, new_col, m, n, component);
                good = good && child_good;
            }
        }

        return good;
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' && !vis[i][j]) {
                    vector<pair<int, int>> component;
                    bool good = dfs(board, vis, i, j, m, n, component);
                    if (good) {
                        for (auto& p : component) {
                            board[p.first][p.second] = 'X';
                        }
                    }
                }
            }
        }
    }
};