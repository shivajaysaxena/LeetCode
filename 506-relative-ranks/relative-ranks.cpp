class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int, int>> scoreIndex;
        vector<string> ans(score.size());

        for (int i = 0; i < score.size(); i++) {
            scoreIndex.push_back({score[i], i});
        }

        sort(scoreIndex.begin(), scoreIndex.end());

        int rank = score.size() + 1;
        for (auto i : scoreIndex) {
            int index = i.second;
            rank--;

            if (rank == 1) {
                ans[index] = "Gold Medal";
                continue;
            }
            if (rank == 2) {
                ans[index] = "Silver Medal";
                continue;
            }
            if (rank == 3) {
                ans[index] = "Bronze Medal";
                continue;
            }

            ans[index] = to_string(rank);
        }

        return ans;
    }
};