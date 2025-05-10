class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> largeint = digits;
        int i = largeint.size() - 1;
        if (largeint[i] != 9) {
            largeint.back() += 1;
        } else {
            largeint[i] += 1;
            for (i; i > -1; i--) {
                if (largeint[i] == 10 && i == 0) {
                    largeint[i] = 0;
                    largeint.insert(largeint.begin(), 1);
                } else if (largeint[i] == 10 && i >= 1) {
                    largeint[i] = 0;
                    largeint[i - 1] += 1;
                }
            }
        }
        return largeint;
    }
 
};