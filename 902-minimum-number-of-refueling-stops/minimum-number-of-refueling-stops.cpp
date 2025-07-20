class Solution {
public:
    int minRefuelStops(int target, int startFuel,
                       vector<vector<int>>& stations) {
        priority_queue<int> maxHeap; // Max-heap to store available fuels
        int refuels = 0;
        int currFuel = startFuel;
        int i = 0; // index for stations
        int n = stations.size();

        while (currFuel < target) {
            // Push all stations within current fuel range into maxHeap
            while (i < n && stations[i][0] <= currFuel) {
                maxHeap.push(stations[i][1]);
                i++;
            }

            // If no stations available to refuel and not yet reached
            if (maxHeap.empty())
                return -1;

            // Refuel at the station with the most fuel
            currFuel += maxHeap.top();
            maxHeap.pop();
            refuels++;
        }

        return refuels;
    }
};