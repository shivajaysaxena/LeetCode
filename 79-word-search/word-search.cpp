class Solution {
public:
    bool dfs(int x, int y, vector<vector<char>>& board, string word,
             vector<vector<bool>>& vis, int idx) {
        int n = board.size(), m = board[0].size();
        vis[x][y] = true;
        if (idx == word.size() - 1)
            return true;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int x2 = x + i;
                int y2 = y + j;
                if (x2 != x and y2 != y)
                    continue;
                if (x2 >= 0 and x2 < n and y2 >= 0 and y2 < m and
                    !vis[x2][y2] and word[idx + 1] == board[x2][y2]) {
                    if (dfs(x2, y2, board, word, vis, idx + 1))
                        return true;
                }
            }
        }
        vis[x][y] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vector<pair<int, int>> points;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0])
                    points.push_back({i, j});
            }
        }

        for (auto& i : points) {
            if (dfs(i.first, i.second, board, word, vis, 0))
                return true;
        }
        return false;
    }
};