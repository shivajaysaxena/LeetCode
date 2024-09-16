class Solution {
public:
    int findMinDifference(vector<string>& t) {
        vector<int> m;
        for (auto& s : t)
            m.push_back(stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2)));

        sort(m.begin(), m.end());

        int minDiff = 1440 + m[0] - m.back();
        for (int i{1}; i < m.size(); ++i)
            minDiff = min(minDiff, m[i] - m[i - 1]);
            
        return minDiff;
    }
};