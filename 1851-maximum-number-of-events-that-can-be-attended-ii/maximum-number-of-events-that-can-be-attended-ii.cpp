class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end(), [](vector<int>& a, vector<int>& b) {
            if (a[1] == b[1]) {
                return a[0] < b[0];
            }
            return a[1] < b[1];
        });

        int size = static_cast<int>(events.size());

        vector<vector<int>> dp(size + 1, vector<int>(k + 1, 0));

        for (int i = 0; i < size; ++i) {
            int cur_pts = events[i][2];

            int prev_valid = find_prev_valid(events, i);
            for (int j = 1; j < k + 1; ++j) {
                dp[i + 1][j] =
                    max(dp[i][j], dp[prev_valid + 1][j - 1] + cur_pts);
            }
        }
        return dp[size][k];
    }

    int find_prev_valid(vector<vector<int>>& events, int i) {
        int start = events[i][0];
        int prev = i - 1;
        while (prev >= 0 && events[prev][1] >= start) {
            --prev;
        }
        return prev;
    }
};