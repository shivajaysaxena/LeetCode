class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> digitSum(n + 1);
        for (int i = 1; i <= n; ++i) {
            digitSum[i] = digitSum[i / 10] + (i % 10);
        }
        const int MAX_SUM = 9 * 5;
        vector<int> freq(MAX_SUM + 1);
        int maxFreq = 0;
        for (int i = 1; i <= n; ++i) {
            int s = digitSum[i];
            maxFreq = max(maxFreq, ++freq[s]);
        }
        int res = 0;
        for (int count : freq) {
            if (count == maxFreq)
                ++res;
        }
        return res;
    }
};