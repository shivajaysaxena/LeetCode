class Solution {
public:
    string getHappyString(int n, int k) {
        int i = 0;
        string s = "";
        string possible = "abc";
        int total = pow(2, n - 1);
        char prev = '*';
        while (i < n) {
            for (char ch : possible) {
                if (ch == prev)
                    continue;
                if (k > total)
                    k -= total;
                else {
                    // cout<<"s";
                    s += ch;
                    prev = ch;
                    break;
                }
            }
            total /= 2;
            i++;
        }
        if (s.length() != n)
            return "";
        return s;
    }
};