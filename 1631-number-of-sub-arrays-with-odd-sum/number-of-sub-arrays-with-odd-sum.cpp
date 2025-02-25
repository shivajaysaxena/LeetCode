class Solution {
public:
    long long mod = 1000000007;
    int numOfSubarrays(vector<int>& arr) {
        int result = 0, sum = 0;
        vector<int> freq(2, 0);
        freq[0]++;

        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            result += freq[!(sum % 2)];
            freq[sum % 2]++;
            result %= mod;
        }
        return result;
    }
};