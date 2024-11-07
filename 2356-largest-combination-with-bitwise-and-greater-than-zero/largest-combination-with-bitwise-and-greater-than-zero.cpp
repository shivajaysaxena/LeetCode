class Solution {
public:
    int largestCombination(vector<int>& can) {
        vector<int> bitset(32, 0);
        for (auto it : can) {
            for (int i = 0; i < 32; i++) {
                bitset[i] += (it & (1 << i)) != 0;
            }
        }
        return *max_element(bitset.begin(), bitset.end());
    }
};