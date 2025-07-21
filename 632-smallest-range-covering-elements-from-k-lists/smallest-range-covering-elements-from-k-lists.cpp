typedef pair<int, pair<int, int>> Node;
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        priority_queue<Node, vector<Node>, greater<Node>> minHeap;
        int maxVal = INT_MIN;

        // Initialize heap with first element from each list
        for (int i = 0; i < k; i++) {
            minHeap.push({nums[i][0], {i, 0}});
            maxVal = max(maxVal, nums[i][0]);
        }

        int rangeStart = 0, rangeEnd = INT_MAX;

        while (minHeap.size() == k) {
            auto [val, pos] = minHeap.top();
            minHeap.pop();

            if (maxVal - val < rangeEnd - rangeStart) {
                rangeStart = val;
                rangeEnd = maxVal;
            }

            if (pos.second + 1 < nums[pos.first].size()) {
                int nextVal = nums[pos.first][pos.second + 1];
                minHeap.push({nextVal, {pos.first, pos.second + 1}});
                maxVal = max(maxVal, nextVal);
            }
        }

        return {rangeStart, rangeEnd};
    }
};