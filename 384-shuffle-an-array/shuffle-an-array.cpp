class Solution {
public:
    vector<int> original;
    vector<int> temp;
    Solution(vector<int>& nums) {
        original = nums;
        temp = nums;
    }
    vector<int> reset() { return original; }
    vector<int> shuffle() {
        next_permutation(temp.begin(), temp.end());
        return temp;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */