class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> v;
        int i = 0, j = 0;
        while (i < nums.size()) {
            if (i == nums.size() - 1 || nums[i + 1] != nums[i] + 1) {
                if (j == i)
                    v.push_back(to_string(nums[i]));
                else
                    v.push_back(to_string(nums[j]) + "->" + to_string(nums[i]));
                j = ++i;
            } else
                i++;
        }
        return v;
    }
};