class Solution {
public:
    int binarySearch(vector<int> nums){
        if(nums[nums.size() - 1] == 0)
            return nums.size();
        int low = 0;
        int high = nums.size() - 1;
        int idx;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] >= 1){
                idx = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return  idx;
    }
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxCount = 0;
        int maxIndex = 0;
        for(int i=0;i<mat.size();i++){
            sort(mat[i].begin(), mat[i].end());
        }
        for(int i=0;i<mat.size();i++){
            int count = mat[0].size()- binarySearch(mat[i]);
            if(count > maxCount){
                maxCount = count;
                maxIndex = i;
            }
        }
        return {maxIndex, maxCount};
    }
};