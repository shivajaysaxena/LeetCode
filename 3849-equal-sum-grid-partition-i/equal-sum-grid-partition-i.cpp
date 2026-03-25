class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        long double sum = 0.0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                sum += grid[i][j];
            }
        }

        long double hSum = 0.0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                hSum += grid[i][j];
            }
            if(hSum == sum / 2) return true;
        }

        long double vSum = 0.0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                vSum += grid[j][i];
            }
            if(vSum == sum / 2) return true;
        }
        
        return false;
    }
};