class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {

        int negSum = 0;
        int posSum = 0;
        int maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            negSum += nums[i];
            posSum += nums[i];

            if (negSum > 0)
                negSum = 0;
            if (posSum < 0)
                posSum = 0;
            maxi = max(maxi, max(posSum, abs(negSum)));
        }

        return maxi;
    }
};