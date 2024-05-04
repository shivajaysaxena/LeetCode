class Solution {
public:
    int numRescueBoats(vector<int>& arr, int limit) {
        sort(arr.begin(), arr.end());
        int s = 0;
        int count = 0;
        int e = arr.size() - 1;

        while (s <= e) {
            if (arr[s] + arr[e] <= limit) {
                count++;
                s++;
                e--;
            } else {
                count++;
                e--;
            }
        }
        return count;
    }
};