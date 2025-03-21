class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int count_odd = 0;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] % 2) {
                count_odd++;
            }
        }
        if (count_odd % 2 == 0) {
            return size - 1;
        }
        return 0;
    }
};