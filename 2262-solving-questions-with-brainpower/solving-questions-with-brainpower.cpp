
class Solution {
public:
    vector<long long> dp;

    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        dp.resize(n, -1);
        return helper(questions, 0);
    }

private:
    long long helper(vector<vector<int>>& q, int idx) {
        if (idx >= q.size()) {
            return 0;
        }

        if (dp[idx] != -1) {
            return dp[idx];
        }

        int points = q[idx][0];
        long long skip = helper(q, idx + 1);
        long long solve = helper(q, idx + q[idx][1] + 1) + points;

        return dp[idx] = max(skip, solve);
    }
};