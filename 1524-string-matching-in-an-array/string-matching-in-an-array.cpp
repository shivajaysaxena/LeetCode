class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& s, const string& t) {
            return s.size() < t.size();
        });
        const int n = words.size();
        vector<string> ans;
        ans.reserve(n);
        for (int i = 0; i < n - 1; i++) {
            auto& s = words[i];
            for (int j = i + 1; j < n; j++) {
                auto& t = words[j];
                if (t.find(s) != -1) {
                    ans.push_back(s);
                    break;
                }
            }
        }
        return ans;
    }
};