class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev = {1};
        if (rowIndex == 0)
            return prev;

        for (int i = 1; i <= rowIndex; i++) {
            vector<int> temp;
            for (int j = 0; j < prev.size() + 1; j++) {
                if (j == 0 || j == prev.size())
                    temp.push_back(1);
                else
                    temp.push_back(prev[j - 1] + prev[j]);
            }
            prev = temp;
        }
        return prev;
    }
};