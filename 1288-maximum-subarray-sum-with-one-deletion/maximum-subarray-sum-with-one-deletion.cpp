class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int nodel = arr[0];     // no deletion
        int onedel = LLONG_MIN; // one deletion
        int maxi = arr[0];

        for (int i = 1; i < n; i++) {
            onedel = max(nodel, onedel + arr[i]);
            nodel = max(arr[i], nodel + arr[i]);
            maxi = max(maxi, max(nodel, onedel));
        }

        return maxi;
    }
};