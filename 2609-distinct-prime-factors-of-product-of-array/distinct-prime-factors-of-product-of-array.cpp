class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> m;
        long long cnt = 0;
        for (auto p : nums) {
            int j = p;
            for (long long i = 2; i * i <= j; i++) {
                if (j % i == 0) {
                    m.insert(i);
                    while (j % i == 0) {
                        j = j / i;
                    }
                }
            }
            if (j > 1)
                m.insert(j);
        }
        return m.size();
    }
};