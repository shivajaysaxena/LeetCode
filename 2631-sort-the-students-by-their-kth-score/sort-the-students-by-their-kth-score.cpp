class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        vector<vector<int>> ans;
        vector<pair<int, vector<int>>> det;
        for (auto i : score) {
            det.push_back({i[k], i});
        }
        sort(det.begin(), det.end());
        for (int i = det.size() - 1; i >= 0; i--) {
            ans.push_back(det[i].second);
        }
        return ans;
    }
};