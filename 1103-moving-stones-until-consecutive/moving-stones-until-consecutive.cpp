class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> arr = {a, b, c};
        vector<int> ans;
        sort(arr.begin(), arr.end());
        a = arr[0], b = arr[1], c = arr[2];
        int maxi = c - a - 2;
        int mini = 0;
        if (abs(b - a) == 2 || abs(c - b) == 2)
            mini = 1;
        else {
            if (a < b - 1)
                mini++;
            if (b < c - 1)
                mini++;
        }
        ans.push_back(mini);
        ans.push_back(maxi);
        return ans;
    }
};