class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string result = nums[0];

        for (int i = 0; i < n; i++) {
            if (nums[i][i] == '1') {
                result[i] = '0';
            } else {
                result[i] = '1';
            }
        }

        return result;
    }
};
