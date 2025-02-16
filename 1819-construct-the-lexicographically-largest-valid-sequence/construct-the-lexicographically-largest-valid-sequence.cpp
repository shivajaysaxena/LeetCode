class Solution {
private:
    vector<int> ans;
    bool found = false;

    void fill(int i, int n, vector<int>& digit, vector<bool>& visited,
              vector<bool>& used) {
        if (i == 2 * n - 1) {
            ans = digit;
            found = true;
            return;
        }

        if (visited[i]) {
            fill(i + 1, n, digit, visited, used);
            return;
        }

        for (int j = n; j > 0; j--) {
            if (used[j])
                continue;

            visited[i] = true;
            digit[i] = j;
            used[j] = true;

            int secondPos = i + j;
            if (j == 1 || (secondPos < 2 * n - 1 && !visited[secondPos])) {
                bool secondVisited = false;
                if (j != 1) {
                    visited[secondPos] = true;
                    digit[secondPos] = j;
                    secondVisited = true;
                }

                fill(i + 1, n, digit, visited, used);
                if (found)
                    return;

                if (secondVisited) {
                    visited[secondPos] = false;
                    digit[secondPos] = 0;
                }
            }

            visited[i] = false;
            digit[i] = 0;
            used[j] = false;
        }
    }

public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> digit(2 * n - 1, 0);
        vector<bool> visited(2 * n - 1, false);
        vector<bool> used(n + 1, false);
        fill(0, n, digit, visited, used);
        return ans;
    }
};