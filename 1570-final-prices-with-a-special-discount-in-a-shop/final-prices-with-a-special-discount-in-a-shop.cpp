class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans = prices;
        stack<int> s;

        for (int i = prices.size() - 1; i >= 0; i--) {
            while (!s.empty() && prices[i] < s.top())
                s.pop();
            ans[i] -= s.empty() ? 0 : s.top();
            s.push(prices[i]);
        }

        return ans;
    }
};