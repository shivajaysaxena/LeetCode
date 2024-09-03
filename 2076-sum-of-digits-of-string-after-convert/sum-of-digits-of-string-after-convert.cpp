class Solution {
public:
    int getLucky(string s, int k) {
        string snumber = "";
        for (char c : s) {
            snumber += to_string(c - 'a' + 1);
        }
        while (k > 0) {
            int res = 0;
            for (char c : snumber) {
                res += c - '0';
            }
            snumber = to_string(res);
            k--;
        }
        return stoi(snumber);
    }
};