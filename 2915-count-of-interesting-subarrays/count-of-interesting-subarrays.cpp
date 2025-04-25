class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int, long long> freq;
        freq[0] = 1;

        long long res = 0;
        int count = 0;

        for (int num : nums) {
            if (num % modulo == k)
                count++;

            int currMod = count % modulo;
            int targetMod = (currMod - k + modulo) % modulo;

            res += freq[targetMod];
            freq[currMod]++;
        }

        return res;
    }
};