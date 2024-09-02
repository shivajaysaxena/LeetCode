class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int i = 0;
        int size = chalk.size();
        int c = 0;
        long long sum = 0;
        for (int i = 0; i < size; i++) {
            sum += chalk[i];
        }
        if (k % sum == 0)
            return 0;
        int remainder = k % sum;
        while (remainder > 0) {
            remainder -= chalk[i % size];
            if (remainder < 0) {
                break;
            }
            cout << k << " ";
            i++;
        }
        return i % size;
    }
};