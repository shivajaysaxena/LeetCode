class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        int n = nums.size();
        vector<int> opCnt(n + 1, 0);
        for (vector<int> x : q) {
            opCnt[x[0]] += 1;
            opCnt[x[1] + 1] -= 1;
        }
        for (int i = 1; i < n; i++)
            opCnt[i] += opCnt[i - 1];
        for (int i = 0; i < n; i++)
            if (nums[i] > opCnt[i])
                return false;
        return true;
    }
};