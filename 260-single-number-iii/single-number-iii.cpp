class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> v;
        int n = nums.size();

        for (int num : nums) {
            mp[num]++;
        }

        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (it->second == 1) {
                v.push_back(it->first);
            }
        }
        
        return v;
    }
};