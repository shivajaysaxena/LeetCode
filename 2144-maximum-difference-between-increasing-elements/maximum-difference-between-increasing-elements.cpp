class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int diff = -1;
        int mn = nums[0];

        for(int i=1;i<nums.size();i++){
            if(nums[i] > mn){
                diff = max({nums[i] - mn, diff});
            }
            if(nums[i] < mn){mn = nums[i];}
        }

        return diff;
    }
};