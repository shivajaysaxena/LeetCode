class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (auto i : stones)
            pq.push(i);
        if (pq.top() == 1)
            return pq.top();
        while (!pq.empty()) {
            if (pq.size() == 1)
                return pq.top();
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if (x == y)
                continue;
            else {
                pq.push(x - y);
            }
        }
        return 0;
    }
};