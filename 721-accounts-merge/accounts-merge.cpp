class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        unordered_map<string, vector<string>> adjList;
        vector<vector<string>> res;

        for (auto account : accounts) {

            for (int i = 2; i < account.size(); i++) {

                adjList[account[1]].push_back(account[i]);
                adjList[account[i]].push_back(account[1]);
            }
        }

        unordered_map<string, bool> visited;

        for (auto account : accounts) {

            if (visited[account[1]])
                continue;

            vector<string> emails;
            dfs(account[1], adjList, visited, emails);

            sort(emails.begin(), emails.end());
            emails.insert(emails.begin(), account[0]);

            res.push_back(emails);
        }

        return res;
    }

    void dfs(string curr, unordered_map<string, vector<string>>& adjList,
             unordered_map<string, bool>& visited, vector<string>& emails) {

        visited[curr] = true;
        emails.push_back(curr);

        for (auto nbr : adjList[curr]) {

            if (!visited[nbr]) {
                dfs(nbr, adjList, visited, emails);
            }
        }
    }
};