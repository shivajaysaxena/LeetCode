class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int total = tickets[k];
        for (int i = 0; i < k; i++) {
            total += min(tickets[k], tickets[i]);
        }
        for (int i = k + 1; i < tickets.size(); i++) {
            total += min(tickets[k] - 1, tickets[i]);
        }
        return total;
    }
};