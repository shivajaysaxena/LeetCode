class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int ma = arr[n - 1];
        arr[n - 1] = -1;
        for (int i = n - 2; i >= 0; i--) {
            int c = ma;
            ma = max(arr[i], ma);
            arr[i] = c;
        }
        return arr;
    }
};