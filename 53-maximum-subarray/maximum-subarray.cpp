class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0;
        int maxSum = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            currSum += nums[i];
            maxSum = max(maxSum, currSum);
            if (currSum < 0) {
                currSum = 0;
            } // written at end because if all elements -ve then sum should be
              // -ve but
            // if this written above sum would become 0 and wrong answer. :D
        }
        return maxSum;
    }
};