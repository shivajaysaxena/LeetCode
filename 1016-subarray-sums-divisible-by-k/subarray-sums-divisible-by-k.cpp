class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int, int> mp;
        mp[0]++;
        int s = 0, cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            s = (s + nums[i] % k + k) % k;
            cnt += mp[s];
            mp[s]++;
        }
        return cnt;
    }
};