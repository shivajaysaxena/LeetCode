class Solution {
public:
    int func(int i, int j, vector<vector<int>>& dp) {
        // Base case
        if (i == 0 && j == 0)
            return 1;

        /* If we go out of bounds or reach
        a blocked cell, there are no ways.*/
        if (i < 0 || j < 0)
            return 0;

        /* If we have already computed the number
        of ways for this cell, return it.*/
        if (dp[i][j] != -1)
            return dp[i][j];

        /* Calculate the number of ways by
        moving up and left recursively.*/
        int up = func(i - 1, j, dp);
        int left = func(i, j - 1, dp);

        // Store the result in dp table and return it.
        return dp[i][j] = up + left;
    }

public:
    /*Function to count the total ways
    to reach (0,0) from (m-1,n-1)*/
    int uniquePaths(int m, int n) {
        /* Initialize a memoization table (dp) to
        store the results of subproblems.*/
        vector<vector<int>> dp(m, vector<int>(n, -1));

        // Return the total count(0 based indexing)
        return func(m - 1, n - 1, dp);
    }
};