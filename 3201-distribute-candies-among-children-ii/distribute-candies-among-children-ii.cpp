class Solution {
public:
    long long distributeCandies(long long n, long long m) {
        if (3 * m < n)
            return 0;
        long long totoal = ((n + 2) * (n + 1)) / 2;
        long long a = n - (m + 1);
        if (a >= 0)
            a = ((a + 1) * (a + 2)) / 2;
        else
            a = 0;
        long long b = n - 2 * (m + 1);
        if (b >= 0)
            b = ((b + 1) * (b + 2)) / 2;
        else
            b = 0;
        long long c = n - 3 * (m + 1);
        if (c >= 0)
            b = ((c + 1) * (c + 2)) / 2;
        else
            c = 0;
        totoal = totoal - (3 * a - 3 * b + c);
        return totoal;
    }
};