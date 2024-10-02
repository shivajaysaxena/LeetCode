class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ans = arr;
        sort(ans.begin(), ans.end());
        unordered_map<int, int> mp;
        int rank = 1;
        for (int i = 0; i < ans.size(); i++) {
            if (mp.find(ans[i]) == mp.end()) {
                mp.insert(make_pair(ans[i], rank));
                rank++;
            }
        }

        for (int j = 0; j < arr.size(); j++) {
            auto it = mp.find(arr[j]);
            ans[j] = it->second;
        }
        return ans;
    }
};