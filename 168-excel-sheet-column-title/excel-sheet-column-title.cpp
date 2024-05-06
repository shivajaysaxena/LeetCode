class Solution {
public:
    void func(int c, string& ans) {
        if (c <= 26) {
            ans += (char)'A' + c - 1;
            return;
        }

        int rem = c % 26;
        if (rem == 0) {
            func((c - 26) / 26, ans);
            ans += (char)+'A' + 25;
        } else {
            func((c) / 26, ans);
            ans += (char)+'A' + rem - 1;
        }
    }
    string convertToTitle(int c) {
        string ans = "";
        func(c, ans);
        return ans;
    }
};