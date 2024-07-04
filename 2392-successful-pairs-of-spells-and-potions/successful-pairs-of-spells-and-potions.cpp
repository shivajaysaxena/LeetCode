class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long suc) {

        sort(p.begin(), p.end());
        vector<int> ans;
        int m = p.size();
        int n = s.size();
        int idx = 0;
        for (int i = 0; i < n; i++) {
            int l = 0;
            int r = m - 1;
            int idx = m;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (static_cast<long long>(s[i]) * p[mid] >= suc) {
                    r = mid - 1;
                    idx = mid;
                } else {
                    l = mid + 1;
                }
            }
            ans.push_back(max(m - idx, 0));
        }
        return ans;
    }
};