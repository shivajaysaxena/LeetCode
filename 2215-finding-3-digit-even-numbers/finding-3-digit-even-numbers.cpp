class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int count[10] = {0};

        for (int digit : digits) {
            count[digit]++;
        }

        vector<int> result;

        for (int num = 100; num <= 999; ++num) {
            if (num % 2 != 0)
                continue;

            int a = num / 100;
            int b = (num / 10) % 10;
            int c = num % 10;

            int tempCount[10] = {0};
            tempCount[a]++;
            tempCount[b]++;
            tempCount[c]++;

            bool valid = true;
            for (int d = 0; d < 10; ++d) {
                if (tempCount[d] > count[d]) {
                    valid = false;
                    break;
                }
            }

            if (valid)
                result.push_back(num);
        }

        return result;
    }
};