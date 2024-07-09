class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int currentTime = 0;
        long long totalwaitTime = 0;
        for (auto customer : customers) {
            int arrival = customer[0];
            int time = customer[1];
            if (currentTime < arrival) {
                currentTime = arrival;
            }
            int waitTime = currentTime + time - arrival;
            totalwaitTime += waitTime;
            currentTime += time;
        }
        return (totalwaitTime * 1.0) / customers.size();
    }
};