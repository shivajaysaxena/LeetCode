class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        sort(nums.rbegin(), nums.rend());
        return nums[k - 1];
    }
};