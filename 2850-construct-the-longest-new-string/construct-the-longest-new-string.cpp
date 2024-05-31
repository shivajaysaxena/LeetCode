class Solution {
public:
    int longestString(int x, int y, int z) {
        int mini = min(x, y);
        int diff = abs(x - y);

        if (diff <= 1) {
            return 2 * (((x + y + z)));
        } else

            return ((mini * 2 + 1) + z) * 2;
    }
};