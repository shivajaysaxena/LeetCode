class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int last = colors[0], ans = 0, count = 1;
        for (int i = 1; i < colors.size(); ++i) {
            count = (colors[i] != last) ? count + 1 : 1;
            if (count >= k)
                ans++;
            last = colors[i];
        }
        for (int i = 0; i < k - 1; ++i) {
            count = (colors[i] != last) ? count + 1 : 1;
            if (count >= k)
                ans++;
            last = colors[i];
        }
        return ans;
    }
};