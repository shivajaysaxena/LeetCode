class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n);
        iota(ans.begin(), ans.begin() + n / 2, -n / 2);
        iota(ans.end() - n / 2, ans.end(), 1);
        return ans;
    }
};