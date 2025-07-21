class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
    vector<string> result;

    void dfs(string src) {
        while (!adj[src].empty()) {
            string next = adj[src].top();
            adj[src].pop();
            dfs(next);
        }
        result.push_back(src);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& ticket : tickets) {
            adj[ticket[0]].push(ticket[1]);
        }
        dfs("JFK");
        reverse(result.begin(), result.end());
        return result;
    }
};
