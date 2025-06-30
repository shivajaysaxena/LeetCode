class Solution {
public:
    vector<int> parent;
    vector<int> size;
    int findParent(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]);
    }
    void unionBySize(int u, int v) {
        int u_parent = findParent(u);
        int v_parent = findParent(v);
        if (u_parent == v_parent)
            return;
        if (size[u_parent] <= size[v_parent]) {
            parent[u_parent] = v_parent;
            size[v_parent] += size[u_parent];
        } else {
            parent[v_parent] = u_parent;
            size[u_parent] += size[v_parent];
        }
        return;
    }
    int makeConnected(int n, vector<vector<int>>& arr) {
        if (arr.size() < n - 1)
            return -1;
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
        int ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            unionBySize(arr[i][0], arr[i][1]);
        }
        for (int i = 0; i < n; i++) {
            if (parent[i] == i) {
                ans++;
            }
        }
        return --ans;
    }
};