class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> temp(k, 0);
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] < 0) {
                temp[(k + (arr[i] % k)) % k]++;
            } else {
                temp[arr[i] % k]++;
            }
        }
        if (temp[0] % 2 == 1)
            return false;
        for (int i = 1; i < k; i++) {
            if (temp[i] != temp[k - i])
                return false;
        }
        return true;
    }
};