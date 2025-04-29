class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi=*max_element(nums.begin(),nums.end());
        long long n=nums.size(),ans=0,cnt=0,left=0;
        for (long long right=0;right<n;right++){
            if (nums[right] == maxi)cnt++;
            while(cnt>=k){
                ans+=(n-right);
                if(nums[left]==maxi) cnt--;
                left++;
            }
        }
        return ans;
    }
};