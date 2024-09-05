class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum_rolles = accumulate(rolls.begin(), rolls.end(), 0);
        int total = (n + m) * mean, miss = total - sum_rolles;
        if (miss > 6 * n || miss < n)
            return {};
        auto [q, r] = div(miss, n);
        vector<int> ans(n, q);
        fill(ans.begin(), ans.begin() + r, q + 1);
        return ans;
    }
};