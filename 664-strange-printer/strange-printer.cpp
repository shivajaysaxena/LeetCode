class Solution {
public:
    int strangePrinter(string s) {
        int size = s.length();
        vector<vector<int>> turnsNeeded(size, vector<int>(size, 0));
        for (int indx = 0; indx < size; indx++) {
            turnsNeeded[indx][indx] = 1;
        }
        for (int len = 2; len <= size; len++) {
            for (int startIndx = 0; startIndx + len - 1 < size; startIndx++) {
                int endIndx = startIndx + len - 1;
                int minPrevStateContri = size;
                for (int brkPtIndx = startIndx; brkPtIndx < endIndx;
                     brkPtIndx++) {
                    int prevStateContri = turnsNeeded[startIndx][brkPtIndx] +
                                          turnsNeeded[brkPtIndx + 1][endIndx];
                    if (s[brkPtIndx] == s[endIndx])
                        prevStateContri--;
                    minPrevStateContri =
                        min(minPrevStateContri, prevStateContri);
                }
                turnsNeeded[startIndx][endIndx] = minPrevStateContri;
            }
        }
        return turnsNeeded[0][size - 1];
    }
};