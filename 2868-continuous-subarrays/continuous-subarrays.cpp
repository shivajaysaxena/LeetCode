class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long cnt = 0;
        map<int, int> hasX;
        for (int l = 0, r = 0; r < n; r++) {
            hasX[nums[r]]++;
            while (l < r && prev(hasX.end())->first - hasX.begin()->first > 2) {
                int f = --hasX[nums[l]];
                if (f == 0) {
                    hasX.erase(nums[l]);
                }
                l++;
            }
            cnt += r - l + 1LL;
        }
        return cnt;
    }
};