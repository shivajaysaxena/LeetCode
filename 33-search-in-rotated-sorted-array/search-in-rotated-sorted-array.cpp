class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto it = find(nums.begin(), nums.end(), target);
        if (it != nums.end()) {
            return it - nums.begin();

        } else {
            return -1;
        }
    }
};