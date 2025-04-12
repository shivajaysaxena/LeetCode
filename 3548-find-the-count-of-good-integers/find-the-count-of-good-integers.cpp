class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        static long long comb[11][11];
        for (int i = 0; i <= 10; i++) {
            comb[i][0] = comb[i][i] = 1;
        }
        for (int i = 2; i <= 10; i++) {
            for (int j = 1; j < i; j++) {
                comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
            }
        }
        int base = 1;
        for (int i = 0; i < (n + 1) / 2; i++)
            base *= 10;

        vector<long long> encodedFreqs;
        for (int half = base / 10; half < base; half++) {
            long long num = half;
            for (int j = 0, mirror = ((n & 1) ? half / 10 : half); j < n / 2;
                 j++)
                num = num * 10 + (mirror % 10), mirror /= 10;
            if (num % k == 0) {
                int freq[10] = {};
                for (int t = 0; t < n; t++)
                    freq[num % 10]++, num /= 10;
                num = 0;
                for (int d = 0; d < 10; d++)
                    num = num * 11 + freq[d];
                encodedFreqs.push_back(num);
            }
        }

        sort(encodedFreqs.begin(), encodedFreqs.end());
        encodedFreqs.erase(unique(encodedFreqs.begin(), encodedFreqs.end()),
                           encodedFreqs.end());

        long long total = 0;
        for (long long code : encodedFreqs) {
            int freq[10] = {};
            for (int d = 9; d >= 0; d--)
                freq[d] = code % 11, code /= 11;
            long long ways = 1;
            for (int i = 0, rem = n; i < 10; i++)
                ways *= comb[i ? rem : rem - 1][freq[i]], rem -= freq[i];
            total += ways;
        }
        return total;
    }
};