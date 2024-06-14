class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> mp;
        mp[0] = 1;
        int crntsum = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            crntsum += nums[i];
            int rem = crntsum-k;
            cnt += mp[rem];
            mp[crntsum] += 1;
        }
        return cnt;
    }
};