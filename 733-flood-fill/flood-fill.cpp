class Solution {
public:
    void dfs(int i, int j, int k, int color, vector<vector<int>>& image) {
        int n = image.size();
        int m = image[0].size();
        image[i][j] = color;
        if (i - 1 >= 0 && image[i - 1][j] == k) {
            dfs(i - 1, j, k, color, image);
        }
        if (i + 1 < n && image[i + 1][j] == k) {
            dfs(i + 1, j, k, color, image);
        }
        if (j - 1 >= 0 && image[i][j - 1] == k) {
            dfs(i, j - 1, k, color, image);
        }
        if (j + 1 < m && image[i][j + 1] == k) {
            dfs(i, j + 1, k, color, image);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int k = image[sr][sc];
        if (k == color) {
            return image;
        }
        dfs(sr, sc, k, color, image);
        return image;
    }
};