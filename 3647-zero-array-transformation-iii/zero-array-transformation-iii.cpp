class Solution {
public:
    int maxRemoval(vector<int>& A, vector<vector<int>>& queries) {
        int n = A.size(), nq = queries.size();
        sort(queries.begin(), queries.end());
        priority_queue<int> h;
        vector<int> end(n + 1, 0);
        int cur = 0, j = 0;
        for (int i = 0; i < n; ++i) {
            cur -= end[i];
            while (j < nq && queries[j][0] <= i) {
                h.push(queries[j][1]);
                j++;
            }
            while (cur < A[i]) {
                if (h.empty() || h.top() < i) {
                    return -1;
                }
                end[h.top() + 1]++;
                h.pop();
                cur++;
            }
        }
        return h.size();
    }
};