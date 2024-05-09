class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(), happiness.rend());
        long long c = 0;
        int i = 0;
        while (i < k) {
            if (happiness[i] <= 0){
                return c;
            } 
            c += happiness[i];
            if (i + 1 < happiness.size()) {
                happiness[i + 1] -= (i + 1);
            }
            i++;
        }
        return c;
    }
};