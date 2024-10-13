class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        vector<int> ans;
        vector<pair<int, int>> merged;
        vector<int> freq(n);
        for (int i = 0; i < n; i++) {
            for (int num : nums[i]) {
                merged.push_back({num, i});
            }
        }
        sort(merged.begin(), merged.end());
        int i = 0, j = 0, len = 1e8;
        int covered = 0;
        while (j < merged.size()) {
            if (freq[merged[j].second] == 0)
                covered++;
            freq[merged[j].second]++;
            while (covered == n) {
                if ((merged[j].first - merged[i].first) < len) {
                    ans = {merged[i].first, merged[j].first};
                    len = merged[j].first - merged[i].first;
                }
                if (freq[merged[i].second] == 1)
                    covered--;
                freq[merged[i].second]--;
                i++;
            }
            j++;
        }
        return ans;
    }
};