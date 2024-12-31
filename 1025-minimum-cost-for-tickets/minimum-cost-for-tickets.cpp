class Solution {
public:
    int dp[366];
    int solve(int ind, vector<int>& days, vector<int>& costs) {
        if (ind >= days.size()) return 0;
        if (dp[ind] != -1) return dp[ind];

        int oneDay = costs[0] + solve(ind + 1, days, costs);

        int day = lower_bound(days.begin(), days.end(), days[ind] + 7) - days.begin();
        int sevenDays = costs[1] + solve(day, days, costs);

        day = lower_bound(days.begin(), days.end(), days[ind] + 30) - days.begin();
        int thirtyDays = costs[2] + solve(day, days, costs);

        return dp[ind] = min(oneDay, min(sevenDays, thirtyDays));
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp, -1, sizeof(dp));
        return solve(0, days, costs);
    }
};