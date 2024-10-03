class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum = 0;
        for(auto it : nums) {
            sum += it;
        }
        long long to_remove = sum % p;
        if(to_remove == 0){
            return 0;
        } 
        unordered_map<int, int> mp;
        mp[0] = -1;  
        int n = nums.size();
        int mini = n; 
        int prefixSum = 0;
        for(int i = 0; i < nums.size(); ++i) {
            prefixSum = (prefixSum + nums[i]) % p;  
            long long target = (prefixSum - to_remove + p) % p;  
            if(mp.find(target) != mp.end()) {
                mini = min(mini, i - mp[target]);  
            }
            mp[prefixSum] = i;  
        }
        if(mini == n){
            return -1;
        }
        return mini;
    }
};