class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(-1);
        stack<pair<int, int>> st;
        int largestArea{};

        for (int i = 0; i < (int)heights.size(); i++) {
            int startIdx{i};
            while (!st.empty() && heights[i] < st.top().first) {
                auto [height, idx] = st.top();
                st.pop();
                largestArea = max(largestArea, height * (i - idx));
                startIdx = idx;
            }
            st.push({heights[i], startIdx});
        }

        return largestArea;
    }
};