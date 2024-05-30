class Solution {
public:
    void get(vector<int>& digits, int n) {
        digits.clear();
        if (n >= 10)
            get(digits, n / 10);
        digits.push_back(n % 10);
    }

    bool isHappy(int n) {
        if (n == 1)
            return true;
        vector<int> digits;
        get(digits, n);
        int sumSquares;
        int limit = 0;

        while (true) {
            if (limit >= 100)
                return false;
            sumSquares = 0;
            for (int i = 0; i < digits.size(); ++i) {
                sumSquares += digits[i] * digits[i];
            }

            if (sumSquares == 1)
                return true;
            get(digits, sumSquares);
            limit++;
        }
        return false;
    }
};