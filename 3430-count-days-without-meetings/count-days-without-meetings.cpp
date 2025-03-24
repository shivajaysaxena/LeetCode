class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        if (meetings.empty()){
            return days;  
        } 
        
        sort(meetings.begin(), meetings.end());
        vector<pair<int, int>> mInter;
        int currSt = meetings[0][0];
        int currE = meetings[0][1];

        for (int i = 1; i < meetings.size(); ++i) {
            if (meetings[i][0] <= currE + 1) {
                currE = max(currE, meetings[i][1]);
            } else {
                mInter.push_back({currSt, currE});
                currSt = meetings[i][0];
                currE = meetings[i][1];
            }
        }
        mInter.push_back({currSt, currE});
        int empDay = 0;
        if (mInter[0].first > 1) {
            empDay += mInter[0].first - 1;
        }
        for (int i = 1; i < mInter.size(); ++i) {
            empDay += mInter[i].first - mInter[i - 1].second - 1;
        }
        if (mInter.back().second < days) {
            empDay += days - mInter.back().second;
        }

        return empDay;
        
    }
};