#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        auto isValid = [&](int effort) {
            vector<vector<bool>> visited(n, vector<bool>(m, false));
            queue<pair<int, int>> q;
            q.push({0, 0});
            visited[0][0] = true;

            vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop();

                if (r == n - 1 && c == m - 1)
                    return true;

                for (auto& [dr, dc] : dirs) {
                    int nr = r + dr, nc = c + dc;
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                        !visited[nr][nc]) {
                        int diff = abs(heights[nr][nc] - heights[r][c]);
                        if (diff <= effort) {
                            visited[nr][nc] = true;
                            q.push({nr, nc});
                        }
                    }
                }
            }

            return false;
        };

        int low = 0, high = 1e6, ans = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (isValid(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
