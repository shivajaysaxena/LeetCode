class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isWord;

    TrieNode() : isWord(false) {}

    void addWord(const string& word) {
        TrieNode* cur = this;
        for (char c : word) {
            if (!cur->children.count(c)) {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->isWord = true;
    }
};

class Solution {
    unordered_set<string> result;
    vector<vector<bool>> visited;

public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (const string& word : words) {
            root->addWord(word);
        }
        int ROWS = board.size(), COLS = board[0].size();
        visited.assign(ROWS, vector<bool>(COLS, false));

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                dfs(board, r, c, root, "");
            }
        }

        return vector<string>(result.begin(), result.end());
    }

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node,
             string word) {
        int ROWS = board.size(), COLS = board[0].size();
        if (r < 0 || c < 0 || r >= ROWS || c >= COLS || visited[r][c] ||
            !node->children.count(board[r][c]))
            return;
        visited[r][c] = true;

        node = node->children[board[r][c]];
        word += board[r][c];
        if (node->isWord)
            result.insert(word);

        dfs(board, r + 1, c, node, word);
        dfs(board, r - 1, c, node, word);
        dfs(board, r, c + 1, node, word);
        dfs(board, r, c - 1, node, word);

        visited[r][c] = false;
    }
};