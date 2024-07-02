class RecentCounter {
public:
    queue<int> q;
    RecentCounter() {}

    int ping(int t) {
        int lower = t - 3000;
        while (!q.empty() && lower > q.front()) {
            q.pop();
        }
        q.push(t);
        return q.size();
    }
};
