class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        map<long long, long long> m;
        long long sum = 0;
        long long cnt = 0;
        m[0] = 1;
        for (int x : nums) {
            sum = sum ^ x;
            cnt += m[sum];
            m[sum]++;
        }
        return cnt;
    }
};