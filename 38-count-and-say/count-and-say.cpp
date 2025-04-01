class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        string prev = countAndSay(n - 1);
        int len = prev.length();
        string ans = "";
        int count = 1;
        for (int i = 1; i < len; i++) {
            if (prev[i] == prev[i - 1])
                count++;
            else {
                ans.push_back('0' + count);
                ans.push_back(prev[i - 1]);
                count = 1;
            }
        }
        ans.push_back('0' + count);
        ans.push_back(prev[len - 1]);

        return ans;
    }
};