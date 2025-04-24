class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();

        set<int> s;
        for (int i : nums)
            s.insert(i);
        int target_size = 0;

        int ans = 0;
        unordered_map<int, int> mp;
        int l = 0, r = 0;
        while (l < n) {
            while (r < n && mp.size() < s.size()) {
                mp[nums[r]]++;
                r++;
            }
            if (mp.size() == s.size()) {
                ans += n - (r - 1);
            }
            mp[nums[l]]--;
            if (mp[nums[l]] == 0) {
                mp.erase(nums[l]);
            }
            l++;
        }

        return ans;
    }
};