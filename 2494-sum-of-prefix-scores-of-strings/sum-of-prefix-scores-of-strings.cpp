class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> out(words.size(), 0);
        vector<pair<int, int>> prev_longest_match;
        int c_ind;
        int min_len;
        for (int i = 0; i < words.size(); i++) {
            out[i] += words[i].size();
            pair<int, int> longest_match = {-1, 0};
            vector<int> matches;
            for (int j = 0; j < i; j++) {
                min_len = min(words[i].size(), words[j].size());
                pair<int, int>& prev_match = prev_longest_match[j];
                if (prev_match.first == -1) {
                    c_ind = 0;
                } else {
                    c_ind = min(matches[prev_match.first], prev_match.second);
                }
                while (c_ind < min_len && words[i][c_ind] == words[j][c_ind]) {
                    c_ind++;
                }
                out[i] += c_ind;
                out[j] += c_ind;
                if (c_ind > longest_match.second) {
                    longest_match.first = j;
                    longest_match.second = c_ind;
                }
                matches.push_back(c_ind);
            }
            prev_longest_match.push_back(longest_match);
        }
        return out;
    }
};