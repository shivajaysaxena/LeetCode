class Solution {
public:
    int dp[301][401];
    int constraints[301];
    int mod = 1e9 + 7;

    int countPermutations(int index, int currentSum, int totalElements) {

        if (index == totalElements)
            return 1;

        if (dp[index][currentSum] != -1)
            return dp[index][currentSum];

        int result = 0;

        if (constraints[index] == -1) {
            for (int j = 0; j <= index; j++) {
                if (currentSum + index - j <= 400)
                    result = (result + countPermutations(index + 1,
                                                         currentSum + index - j,
                                                         totalElements)) %
                             mod;
            }
        } else {
            for (int j = 0; j <= index; j++) {
                if (currentSum + index - j == constraints[index])
                    result = (result + countPermutations(index + 1,
                                                         currentSum + index - j,
                                                         totalElements)) %
                             mod;
            }
        }

        return dp[index][currentSum] = result % mod;
    }

    int numberOfPermutations(int n, vector<vector<int>>& restricted) {
        memset(dp, -1, sizeof(dp));
        memset(constraints, -1, sizeof(constraints));

        for (int i = 0; i < restricted.size(); i++) {
            constraints[restricted[i][0]] = restricted[i][1];
        }

        return countPermutations(0, 0, n);
    }
};