class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int res = 0, n = colors.size();
        for (int i = 0; i < n; i++) {
            if (i == 0 && colors[i] != colors[n - 1] &&
                colors[i] != colors[i + 1])
                res++;
            else if (i == n - 1 && colors[i] != colors[0] &&
                     colors[i] != colors[i - 1])
                res++;
            else if (i != 0 && i != n - 1 && colors[i] != colors[i - 1] &&
                     colors[i] != colors[i + 1])
                res++;
        }
        return res;
    }
};