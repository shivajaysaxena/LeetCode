class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> ans;
        ans.push_back(0);
        int sum = 0;
        for (int i = 0; i < gain.size(); i++) {
            sum += gain[i];
            ans.push_back(sum);
        }
        int maxi = INT_MIN;
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] > maxi) {
                maxi = ans[i];
            }
        }
        return maxi;
    }
};