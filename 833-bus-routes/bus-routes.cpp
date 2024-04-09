class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        int n = routes.size();
        unordered_map<int, bool> vis;
        unordered_map<int, vector<int>> mp;
        bool b = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < routes[i].size(); ++j) {
                mp[routes[i][j]].push_back(i);
                if (routes[i][j] == target) b = 1;
            }
        }
        if (!b) return -1;
        int ans = 1e9;
        queue<array<int,2>> q;
        q.push({1, source});
        while (q.size()) {
            int sz = q.size();
            vis[q.front()[1]] = 1;
            for (int i = 0; i < sz; ++i) {
                int nd = q.front()[1];
                int dis = q.front()[0];
                q.pop();
                for (auto x : mp[nd]) {
                    for (auto v : routes[x]) {
                        if (vis[v]) continue;
                        if (v == target) return dis;
                        vis[v] = 1;
                        q.push({dis+1, v});
                    }
                }
            }
        }
        return -1;
    }
};