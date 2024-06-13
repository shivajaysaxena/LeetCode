class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int crntsum = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            crntsum += nums[i];
            if (crntsum == k) {
                cnt++;
            }
            if (mp.find(crntsum - k) != mp.end())
                cnt += mp[crntsum - k];

            mp[crntsum]++;
        }
        return cnt;
    }
};