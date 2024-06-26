class Solution {
public:
    string HEX = "0123456789abcdef";
    string toHex(int num) {
        if (num == 0)
            return "0";
        string ans;
        int count = 0;
        while (num && count++ < 8) {
            ans = HEX[(num & 0xf)] + ans;
            num >>= 4;
        }
        return ans;
    }
};