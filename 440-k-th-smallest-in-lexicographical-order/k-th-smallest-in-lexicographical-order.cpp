class Solution {
public:
    long countNumbers(long curr, int n) {
        long count = 0;
        long next = curr + 1;
        while (curr <= n) {
            count += min((long)n + 1, next) - curr;
            curr *= 10;
            next *= 10;
        }
        return count;
    }

    int findKthNumber(int n, int k) {
        long curr = 1;
        k--;

        while (k > 0) {
            long count = countNumbers(curr, n);
            if (count <= k) {
                k -= count;
                curr++;
            } else {
                curr *= 10;
                k--;
            }
        }

        return curr;
    }
};