class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int gIndx = 0, gSz = g.size(), sSz = s.size();
        for (int indx = 0; indx < sSz; indx++) {
            if (gIndx < gSz && g[gIndx] <= s[indx]) {
                gIndx++;
            }
        }
        return gIndx;
    }
};