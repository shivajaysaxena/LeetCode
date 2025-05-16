class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        vector<pair<int, double>> cars;
        for (int i = 0; i < position.size(); ++i) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }
        sort(cars.begin(), cars.end());
        stack<double> st;
        for (int i = 0; i < position.size(); ++i) {
            double time = cars[i].second;
            while (!st.empty() && time >= st.top()) {
                st.pop();
            }
            st.push(time);
        }
        return st.size();
    }
};