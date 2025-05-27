// A hash function used to hash a pair of any kind
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);

        if (hash1 != hash2) {
            return hash1 ^ hash2;
        }

        // If hash1 == hash2, their XOR is zero.
        return hash1;
    }
};
struct edge {
    pair<int, int> p1;
    pair<int, int> p2;
    int dis;
};
bool compare_edges(edge e1, edge e2) { return (e1.dis < e2.dis); }
class DSU {
    unordered_map<pair<int, int>, pair<int, int>, hash_pair> parent;
    unordered_map<pair<int, int>, int, hash_pair> rank;

public:
    DSU(vector<vector<int>>& points) {
        for (auto point : points) {
            pair<int, int> p = make_pair(point[0], point[1]);
            rank[p] = 1;
        }
    }
    pair<int, int> find(pair<int, int> p) {
        if (parent.find(p) == parent.end()) {
            return p;
        }
        return parent[p] = find(parent[p]);
    }
    void unite(pair<int, int> p1, pair<int, int> p2) {
        pair<int, int> s1 = find(p1);
        pair<int, int> s2 = find(p2);
        if (!(s1 == s2)) {
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            } else {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};
class Graph {
    int V;
    unordered_map<pair<int, int>, list<pair<pair<int, int>, int>>, hash_pair> g;

public:
    Graph(int V) { this->V = V; }
    void add(pair<int, int>& p1, pair<int, int>& p2) {
        int dis = abs(p1.first - p2.first) + abs(p1.second - p2.second);
        pair<pair<int, int>, int> edge = make_pair(p2, dis);
        g[p1].push_back(edge);
    }
    vector<edge> sort_this() {
        vector<edge> edges;
        for (auto x : g) {
            edge e;
            e.p1 = x.first;
            list<pair<pair<int, int>, int>> L = x.second;
            for (auto nbrs : L) {
                e.p2 = nbrs.first;
                e.dis = nbrs.second;
                edges.push_back(e);
            }
        }
        sort(edges.begin(), edges.end(), compare_edges);
        return edges;
    }
    int kruskal_mst(vector<vector<int>>& points) {
        vector<edge> edgelist = sort_this();
        DSU S(points);
        int ans = 0;
        for (edge a : edgelist) {
            int dis = a.dis;
            pair<int, int> p1 = a.p1;
            pair<int, int> p2 = a.p2;
            if (S.find(p1) != S.find(p2)) {
                S.unite(p1, p2);
                ans += dis;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        // 1. making a weighted graph
        Graph G(V);
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                pair<int, int> p1, p2;
                p1 = {points[i][0], points[i][1]};
                p2 = {points[j][0], points[j][1]};
                G.add(p1, p2);
            }
        }

        return G.kruskal_mst(points);
    }
};