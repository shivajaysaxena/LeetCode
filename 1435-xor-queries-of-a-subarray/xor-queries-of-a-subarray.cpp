class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        unordered_map<int, int> mp;
        int temp = 0;
        for (int i = 0; i < arr.size(); i++) {
            temp = temp ^ arr[i];
            mp[i] = temp;
        }
        vector<int> ans;
        for (auto it : queries) {
            if (it[0] > 0) {
                ans.push_back(mp[it[0] - 1] ^ mp[it[1]]);
            } else {
                ans.push_back(mp[it[1]]);
            }
        }
        return ans;
    }
};