class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> uniqueNums;

        uniqueNums.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                uniqueNums.push_back(nums[i]);
            }
        }

        int count = 0;
        for (int i = 1; i < uniqueNums.size() - 1; i++) {
            if ((uniqueNums[i] > uniqueNums[i - 1] &&
                 uniqueNums[i] > uniqueNums[i + 1]) ||
                (uniqueNums[i] < uniqueNums[i - 1] &&
                 uniqueNums[i] < uniqueNums[i + 1])) {
                count++;
            }
        }

        return count;
    }
};
