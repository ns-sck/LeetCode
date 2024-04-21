class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> vis(n+1);
        vector<vector<int>> adj(n+1, vector<int>());
        queue<int> q;
        for (auto p : edges) {
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }
        q.push(source);
        while (q.size()) {
            int nd = q.front();
            cout << nd << '\n';
            q.pop();
            if (nd == destination) return 1;
            vis[nd] = 1;
            for (auto ng : adj[nd]) {
                if (!vis[ng]) {
                    vis[ng] = 1;
                    q.push(ng);
                }
            }
        }
        return 0;
    }
};