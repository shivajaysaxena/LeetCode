class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(), capacity.end());
        int sum = accumulate(apple.begin(), apple.end(), 0);
        int i = 0;
        while (sum > 0) {
            i++;
            sum -= capacity[capacity.size() - i];
        }
        return i;
    }
};