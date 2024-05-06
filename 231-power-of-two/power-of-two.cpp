class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return 0;
        double x = log2(n);
        return x == (int)x;
    }
};