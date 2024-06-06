class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        unordered_map<int, int> count;

        for (auto i : nums1)
            count[i]++;

        for (auto i : nums2) {
            if (count.find(i) != count.end()) {
                v.push_back(i);
                count.erase(i);
            }
        }
        return v;
    }
};