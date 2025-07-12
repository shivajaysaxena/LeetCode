class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(begin(pairs), end(pairs),
             [&](const vector<int>& v1, const vector<int>& v2) -> bool {
                 return v1[1] < v2[1];
             });

        int prevMeeting = 0, maxi = 1;
        for (int i = 1; i < pairs.size(); ++i) {
            if (pairs[i][0] > pairs[prevMeeting][1])
                prevMeeting = i, ++maxi;
        }
        return maxi;
    }
};