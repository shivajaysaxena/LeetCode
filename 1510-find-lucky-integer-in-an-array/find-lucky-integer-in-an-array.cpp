class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int num : arr) {
            freq[num]++;
        }
        int max_lucky = -1;
        for (auto [num, count] : freq) {
            if (num == count) {
                max_lucky = max(max_lucky, num);
            }
        }

        return max_lucky;
    }
};