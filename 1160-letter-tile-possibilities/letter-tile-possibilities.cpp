class Solution {
    int size = 0;
    unordered_set<string> st;

    void dfs(string& tiles, vector<char>& vct, string curr) {
        if (curr != "") {
            st.insert(curr);
        }
        for (int i = 0; i < size; i++) {
            if (vct[i] != '$') {
                continue;
            }
            vct[i] = tiles[i];
            dfs(tiles, vct, curr + tiles[i]);
            vct[i] = '$';
        }
    }

public:
    int numTilePossibilities(string tiles) {
        size = tiles.size();
        vector<char> vct(size, '$');
        dfs(tiles, vct, "");
        return st.size();
    }
};