class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string ans = "";
        while (n != 0) {
            ans += (n % 2 + '0');
            n /= 2;
        }
        int x = 32 - ans.size();
        while (x != 0) {
            ans += '0';
            x--;
        }
        int i = ans.size() - 1;
        int j = 0;
        uint32_t sum = 0;
        while (i >= 0) {
            sum += ((ans[i] - '0') * pow(2, j++));
            i--;
        }
        return sum;
    }
};