class Solution {
public:
    int findComplement(int num) {
        vector<int> temp;
        while (num) {
            temp.push_back(num % 2);
            num /= 2;
        }
        for (int i = 0; i < temp.size(); i++) {
            temp[i] = !temp[i];
        }
        int ans = 0;
        for (int i = temp.size() - 1; i >= 0; i--) {
            ans += temp[i] * pow(2, i);
        }
        return ans;
    }
};