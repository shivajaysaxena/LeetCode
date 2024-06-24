class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        int result = x ^ y;
        while (result > 0) {
            if ((result & 1) > 0) {
                count++;
            }
            result = result >> 1;
        }
        return count;
    }
};