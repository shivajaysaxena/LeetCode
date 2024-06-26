class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> one;
        vector<int> two;
        for (int i = 0; i < n; i++) {
            one.push_back(nums[i]);
        }
        for (int i = n; i < 2 * n; i++) {
            two.push_back(nums[i]);
        }
        nums.clear();
        for (int i = 0; i < n; i++) {
            nums.push_back(one[i]);
            nums.push_back(two[i]);
        }
        return nums;
    }
};