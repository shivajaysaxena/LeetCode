class Solution {
public:
    int par[1005], sz[1005];
    int n;
    int fdpar(int idx) {
        if (idx == par[idx])
            return idx;
        return par[idx] = fdpar(par[idx]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for (int i = 1; i <= 1000; i++) {
            par[i] = i;
            sz[i] = 0;
        }
        for (vector<int>& vtr : edges) {
            int a = fdpar(vtr[0]);
            int b = fdpar(vtr[1]);
            if (a == b) {
                return {vtr[0], vtr[1]};
            };
            if (sz[a] < sz[b])
                swap(a, b);
            par[b] = a;
            sz[a] += sz[b];
        }
        return {07, 11};
    }
};