class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 3)
            return nums[0] + nums[1] + nums[2];

        sort(nums.begin(), nums.end());

        int ans = nums[0] + nums[1] + nums[2];
        if (ans >= target)
            return ans;

        int max = nums[len - 1] + nums[len - 2] + nums[len - 3];
        if (max <= target)
            return max;

        int last = nums[0];
        int left, right, sum, num;
        int dist = abs(ans - target);
        int i = 0;

        for (; i < len - 2; i++) {
            if (i && nums[i] == last)
                continue;
            last = num = nums[i];
            left = i + 1;
            right = len - 1;
            while (left < right) {
                sum = num + nums[left] + nums[right];
                if (sum == target)
                    return sum;
                if (abs(sum - target) < dist) {
                    ans = sum;
                    dist = abs(ans - target);
                }
                if (sum < target) {
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    left++;
                } else {
                    while (left < right && nums[right] == nums[right - 1])
                        right--;
                    right--;
                }
            }
        }
        return ans;
    }
};