class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;

        for (int num : nums) {
            auto it = lower_bound(sub.begin(), sub.end(), num);
            if (it == sub.end()) {
                sub.push_back(num); // Append if num is larger than all elements
            } else {
                *it = num; // Replace the element at the found position
            }
        }

        return sub.size();
    }
};