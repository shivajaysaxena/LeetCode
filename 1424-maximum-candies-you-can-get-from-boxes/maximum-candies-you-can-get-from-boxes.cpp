class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies,
                   vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {
        int n = status.size();
        vector<int> visited(n, 0);
        queue<int> q;

        int candies_count = 0;

        for (int i : initialBoxes)
            q.push(i);

        if (q.empty())
            return 0;

        while (!q.empty()) {

            int box = q.front();
            q.pop();

            if (visited[box])
                continue;
            visited[box] = true;

            if (status[box] == 0) {
                // q.push(box);
                continue;
            }

            candies_count += candies[box];
            candies[box] = -1;

            for (int i : containedBoxes[box]) {
                if (candies[i] == -1 || visited[i])
                    continue;
                q.push(i);
            }

            for (int i : keys[box]) {
                status[i] = 1;
                if (candies[i] != -1 && visited[i]) {
                    visited[i] = false;
                    q.push(i);
                }
            }
        }

        return candies_count;
    }
};