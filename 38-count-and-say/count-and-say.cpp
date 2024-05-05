class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        string recAns = countAndSay(n - 1);
        string result = "";
        int i = 0, len = recAns.length();
        while (i < len) {
            int cnt = 0;
            char ch = recAns[i];

            while (i < len && ch == recAns[i]) {
                i++;
                cnt++;
            }

            result.push_back((cnt + '0'));
            result.push_back(ch);
        }
        return result;
    }
};