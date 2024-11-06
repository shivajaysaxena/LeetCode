class Solution {
private : 
    bool IsSorted(vector<int> nums) {
        int n = nums.size();
        for(int i = 0;i < n-1;i++) {
            if(nums[i] > nums[i+1]) {
                return false;
            }
        }
        return true;
    }
public:
    bool canSortArray(vector<int>& nums) {
        int size = nums.size();
        if(IsSorted(nums)) {
            return true;
        } else {
            for(int i =0;i<size;i++) {
                for(int j = 0 ;j < size - i - 1;j++) {
                    if(nums[j] > nums[j+1] && (__builtin_popcount(nums[j]) == __builtin_popcount(nums[j+1]))) {
                        swap(nums[j],nums[j+1]);
                    }
                }
            }
        }

        return IsSorted(nums);
    }
};