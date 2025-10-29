class Solution {
public:
    int smallestNumber(int n) {
        int z = 1;
        for (int i = 0; i <= n; i++) {
            z = (1 << i);
            if (z > n)
                return z - 1;
        }
        return 0;
    }
};