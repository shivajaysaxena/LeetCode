class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto gain = [](double pass, double total) {
            return (pass + 1) / (total + 1) - (pass / total);
        };
        priority_queue<pair<double, pair<int, int>>> maxheap;
        double ans = 0;
        for (auto it : classes) {
            int pass = it[0];
            int total = it[1];
            ans += (double)pass / total;
            maxheap.push({gain(pass, total), {pass, total}});
        }
        for (int i = 0; i < extraStudents; i++) {
            auto [currentgain, data] = maxheap.top();
            maxheap.pop();
            int pass = data.first, total = data.second;
            ans -= (double)pass / total;
            pass += 1;
            total += 1;
            ans += (double)pass / total;
            maxheap.push({gain(pass, total), {pass, total}});
        }
        return ans / classes.size();
    }
};