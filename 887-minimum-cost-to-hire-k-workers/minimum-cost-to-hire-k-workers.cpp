class Solution {
public:
    double mincostToHireWorkers(vector<int>& v, vector<int>& t, int k) {
        vector<pair<double, int>> p;
        for (int i = 0; i < v.size(); i++) {
            p.push_back({(double)t[i] / (double)v[i], v[i]});
        }
        sort(p.begin(), p.end());
        double x = 0, r = INT_MAX;
        priority_queue<int> pq;
        for (auto i : p) {
            x += i.second;
            pq.push(i.second);
            if (pq.size() > k) {
                x -= pq.top();
                pq.pop();
            }
            if (pq.size() == k) {
                double a = x * i.first;
                r = min(r, a);
            }
        }
        return r;
    }
};