class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, vector<int>> diag;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int key = i - j;
                diag[key].push_back(grid[i][j]);
            }
        }
        for (auto &p : diag) {
            int key = p.first;
            if (key >= 0) { 
                sort(p.second.begin(), p.second.end(), greater<int>());
            } else { 
                sort(p.second.begin(), p.second.end());
            }
        }

        unordered_map<int, int> idx; 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int key = i - j;
                grid[i][j] = diag[key][idx[key]++];
            }
        }

        return grid;
    }
};