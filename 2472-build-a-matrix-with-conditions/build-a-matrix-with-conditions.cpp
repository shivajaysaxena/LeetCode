class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions,
                                    vector<vector<int>>& colConditions) {
        vector<vector<int>> res(k, vector<int>(k, 0));

        unordered_map<int, int> numToRow;
        unordered_map<int, int> numToCol;

        getOrder(k, rowConditions, numToRow);
        getOrder(k, colConditions, numToCol);

        if (numToRow.size() != k || numToCol.size() != k)
            return {};

        for (int i = 1; i <= k; ++i)
            res[numToRow[i]][numToCol[i]] = i;

        return res;
    }

    void getOrder(int& k, vector<vector<int>>& conditions,
                  unordered_map<int, int>& pos) {
        vector<vector<int>> dependencies(k + 1);
        vector<int> numParents(k + 1, 0);

        for (auto condition : conditions) {
            dependencies[condition[0]].push_back(condition[1]);
            numParents[condition[1]]++;
        }

        int index = 0;
        queue<int> q;

        for (int i = 1; i <= k; ++i) {
            if (numParents[i] == 0) {
                q.push(i);
                pos[i] = index++;
            }
        }

        while (!q.empty()) {
            int parent = q.front();
            q.pop();
            for (auto child : dependencies[parent]) {
                if (--numParents[child] == 0) {
                    q.push(child);
                    pos[child] = index++;
                }
            }
        }
    }
};