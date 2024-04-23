class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (edges.empty()) return {0};
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> pq;
        vector<vector<int>> adj(n, vector<int>());
        vector<int> dgr(n, 0);
        vector<bool> vis(n, 0);
        vector<int> ans;
        for (auto p : edges) {
            ++dgr[p[0]], ++dgr[p[1]];
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }
        for (int i = 0; i < n; ++i) {
            if (dgr[i] == 1) {
                pq.push({dgr[i], i});
                vis[i] = 1;
            }
        }
        int l = -1;
        while (pq.size()) {
            int h = pq.top()[0];
            int u = pq.top()[1];
            cout << u << ' ' << l << ' ' << h << '\n';
            pq.pop();
            if (h > l) {
                l = h;
                ans.clear();
                ans.push_back(u);
            } else if (h == l) {
                ans.push_back(u);
            }
            for (auto v : adj[u]) {
                if (--dgr[v] == 1) {
                    pq.push({h+1, v});
                }
            }
        }
        return ans;
    }
};