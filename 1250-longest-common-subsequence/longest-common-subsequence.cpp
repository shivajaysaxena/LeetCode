class Solution{
private:
    /* Function to find the length of the
    Longest Common Subsequence (LCS)*/
    int func(string& s1, string& s2, int ind1, int ind2, vector<vector<int>>& dp) {
        // Base case
        if (ind1 < 0 || ind2 < 0)
            return 0;

        /* If the result for this pair of indices
        is already calculated, return it*/
        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];

        /* If the characters at the current 
        indices match, increment the LCS length*/
        if (s1[ind1] == s2[ind2])
            return dp[ind1][ind2] = 1 + func(s1, s2, ind1 - 1, ind2 - 1, dp);
        else
            return dp[ind1][ind2] = max(func(s1, s2, ind1, ind2 - 1, dp), func(s1, s2, ind1 - 1, ind2, dp));
    }
public:
    /* Function to calculate the length
    of the Longest Common Subsequence*/
    int longestCommonSubsequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        //Return the result
        return func(str1, str2, n - 1, m - 1, dp);
    }
};