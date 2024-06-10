class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num), st = s;
        int ans = num, n = s.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(st[i], st[j]);
                int x = stoi(st);
                ans = max(ans, x);
                st = s;
            }
        }
        return ans;
    }
};