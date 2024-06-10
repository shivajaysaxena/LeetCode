class Solution {

public:
    int heightChecker(vector<int>& heights) {
        vector<int> realheights = heights;
        sort(realheights.begin(), realheights.end());
        int cnt = 0;
        for (int i = 0; i < realheights.size(); i++) {
            if (heights[i] != realheights[i]) {
                cnt += 1;
            }
        }
        return cnt;
    }
};