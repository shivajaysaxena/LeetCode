class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int answer = 0;
        vector<bool> alreadyChecked(isConnected.size(), false);
        for (int i = 0; i < isConnected.size(); i++) {
            if (dfs(isConnected, i, alreadyChecked)) {
                answer++;
            }
        }
        return answer;
    }
    bool dfs(vector<vector<int>>& isConnected, int cI,
             vector<bool>& alreadyChecked) {
        if (alreadyChecked[cI]) {
            return false;
        }
        alreadyChecked[cI] = true;
        for (int i = 0; i < isConnected.size(); i++) {
            if (isConnected[cI][i] == 1) {
                dfs(isConnected, i, alreadyChecked);
            }
        }
        return true;
    }
};