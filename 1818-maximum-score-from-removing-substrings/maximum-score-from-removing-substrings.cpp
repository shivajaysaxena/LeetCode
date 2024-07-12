class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int acnt = 0, bcnt = 0;
        int result = 0;
        int less = min(x, y);
        for (char c : s) {
            if (c > 'b') {
                result += min(acnt, bcnt) * less;
                acnt = 0;
                bcnt = 0;
            } else if (c == 'a') {
                if (x < y && bcnt > 0) {
                    bcnt--;
                    result += y;
                } else {
                    acnt++;
                }
            } else {
                if (x > y && acnt > 0) {
                    acnt--;
                    result += x;
                } else {
                    bcnt++;
                }
            }
        }
        result += min(acnt, bcnt) * less;
        return result;
    }
};