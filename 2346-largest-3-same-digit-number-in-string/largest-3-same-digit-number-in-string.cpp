class Solution {
public:
    string largestGoodInteger(string nums) {
        string ans = "";
        for (int i = 0; i < (int)nums.size() - 2; i++) {
            if (nums[i] == nums[i+1] && nums[i+1] == nums[i+2]) {
                string curr = nums.substr(i, 3); // take the triple
                ans = max(ans, curr); // lexicographic comparison works here
            }
        }
        return ans;
    }
};
