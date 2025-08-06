class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int m = sqrt(n);
        int block = (n + m - 1) / m;
        int ct = 0;
        vector<int> maxB(block);

        for (int i = 0; i < n; i++) {
            maxB[i / m] = max(maxB[i / m], baskets[i]);
        }

        for (int f : fruits) {
            int bl;
            int unplaced = 1;
            for (bl = 0; bl < block; bl++) {
                if (maxB[bl] < f) {
                    continue;
                }
                int check = 0;
                maxB[bl] = 0;
                for (int i = 0; i < m; i++) {
                    int pos = (bl * m) + i;
                    if (pos < n && baskets[pos] >= f && !check) {
                        baskets[pos] = 0;
                        check = 1;
                    }

                    if (pos < n) {
                        maxB[bl] = max(maxB[bl], baskets[pos]);
                    }
                }
                unplaced = 0;
                break;
            }
            ct += unplaced;
        }
        return ct;
    }
};