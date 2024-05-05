class Solution {
public:
    int nCr(int n, int r) {
        if (r > n)
            return 0;
        if (r == 0 || n == r)
            return 1;
        double res = 0;
        for (int i = 0; i < r; i++) {
            res += log(n - i) - log(i + 1);
        }
        return (int)round(exp(res));
    }

    int uniquePaths(int m, int n) {
        int t = (m - 1) + (n - 1);

        return nCr(t, m - 1);
    }
};