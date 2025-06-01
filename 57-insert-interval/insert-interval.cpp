class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        int n = intervals.size(), i = 0;
        int a = newInterval[0], b = newInterval[1];
        if (n == 0 || intervals[n - 1][1] < a) {
            intervals.push_back(newInterval);
            return intervals;
        }
        vector<vector<int>> ans;
        while (i < n && intervals[i][1] < a) {
            ans.push_back(intervals[i++]);
        }
        a = min(a, intervals[i][0]);
        while (i < n && intervals[i][0] <= b) {
            b = max(b, intervals[i++][1]);
        }
        ans.push_back({a, b});
        while (i < n) {
            ans.push_back(intervals[i++]);
        }

        return ans;
    }
};