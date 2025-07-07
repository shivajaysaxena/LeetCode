class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());

        priority_queue<int, vector<int>, greater<int>> pq;
        int i = 0, n = events.size(), day = 1, count = 0;

        while (true) {
            while (i < n && events[i][0] == day) {
                pq.push(events[i][1]);
                i++;
            }
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }
            if (!pq.empty()) {
                pq.pop();
                count++;
            }
            if (pq.empty() && i == n)
                break;

            day++;
        }

        return count;
    }
};