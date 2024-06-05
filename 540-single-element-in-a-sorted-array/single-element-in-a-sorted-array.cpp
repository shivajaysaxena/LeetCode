class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int xory=0;
        for(int i=0;i<nums.size();i++){
            xory = xory^nums[i];
        }
        return xory;
    }
};