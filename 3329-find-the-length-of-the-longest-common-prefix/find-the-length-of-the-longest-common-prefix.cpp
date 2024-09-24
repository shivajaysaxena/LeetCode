class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;
        for (int i = 0; i < arr1.size(); i++) {
            while (arr1[i] > 0) {
                st.insert(arr1[i]);
                arr1[i] /= 10;
            }
        }
        int maxi = 0;
        for (int i = 0; i < arr2.size(); i++) {
            while (arr2[i] > 0) {
                if (st.find(arr2[i]) != st.end()) {
                    maxi = max(maxi, (int)log10(arr2[i]) + 1);
                }
                arr2[i] /= 10;
            }
        }
        return maxi;
    }
};