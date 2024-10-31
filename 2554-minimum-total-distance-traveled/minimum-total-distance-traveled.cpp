class Solution {
public:
    long long dfs(int robotIdx, int factoryIdx, vector<int>& robot,
                  vector<vector<int>>& factory, vector<vector<long long>>& dp) {
        if (robotIdx == robot.size())
            return 0;
        if (factoryIdx == factory.size())
            return LLONG_MAX;

        if (dp[robotIdx][factoryIdx] != -1)
            return dp[robotIdx][factoryIdx];

        long long res = dfs(robotIdx, factoryIdx + 1, robot, factory, dp);

        long long cost = 0;
        for (int k = 0;
             k < factory[factoryIdx][1] && robotIdx + k < robot.size(); ++k) {
            cost += abs(robot[robotIdx + k] - factory[factoryIdx][0]);
            long long next =
                dfs(robotIdx + k + 1, factoryIdx + 1, robot, factory, dp);
            if (next != LLONG_MAX) {
                res = min(res, cost + next);
            }
        }

        return dp[robotIdx][factoryIdx] = res;
    }
    long long minimumTotalDistance(vector<int>& robot,
                                   vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        int n = robot.size();
        int m = factory.size();
        vector<vector<long long>> dp(n, vector<long long>(m, -1));

        return dfs(0, 0, robot, factory, dp);
    }
};
