class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for (auto s : logs) {
            if (s == "../" && ans) {
                ans--;
            } else if (s != "./" && s != "../") {
                ans++;
            }
        }
        return ans;
    }
};