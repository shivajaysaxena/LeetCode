class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> topologicalsort;
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adjacencyList(numCourses);
        for (auto& i : prerequisites) {
            adjacencyList[i[0]].push_back(i[1]); 
            indegree[i[1]]++;
        }
        
        int index = 0; 
        queue<int> q;
        
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        int top;
        while (!q.empty()) {
            top = q.front();
            cout << top << " ";
            q.pop();
            index++;
            for (auto& i : adjacencyList[top]) {
                indegree[i]--;
                if (indegree[i] == 0)
                    q.push(i);
            }
            topologicalsort.push_back(top);
        }
        if (index < numCourses)
            return {};
        for (int i = 0; i < numCourses / 2; i++) {
            swap(topologicalsort[i], topologicalsort[numCourses - i - 1]);
        }
        return topologicalsort;
    }
};