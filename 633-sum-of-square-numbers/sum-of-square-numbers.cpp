class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long long i = 0; i * i <= c; i++) {
            double r = sqrt(c - i * i);
            if (r == (int)r) {
                return true;
            }
        }
        return false;
    }
};