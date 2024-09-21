class Solution {
    void mydfs(int num, int n, vector<int>& ans) {
        if (num > n)
            return;
        ans.push_back(num);
        for (int i = 0; i <= 9; i++) {
            if ((num * 10 + i) > n)
                break;
            mydfs((num * 10 + i), n, ans);
        }
    }

public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for (int i = 1; i <= 9; i++) {
            if (i <= n)
                mydfs(i, n, ans);
        }
        return ans;
    }
};