class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> productFreq;
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int product = nums[i] * nums[j];
                productFreq[product]++;
            }
        }
        for (auto& [product, count] : productFreq) {
            if (count > 1) {
                res += (count * (count - 1)) / 2;
            }
        }
        return res * 8;
    }
};