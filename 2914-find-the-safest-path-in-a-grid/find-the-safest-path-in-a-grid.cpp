class Solution {
public:

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        ios::sync_with_stdio;
        int r = grid.size();
        int c = grid[0].size();

        array<int, 4> hr{0, 1, 0, -1};
        array<int, 4> vr{-1, 0, 1, 0};

        vector<vector<int>> dis(r, vector<int>(c, 1e9));
        queue<pair<int, pair<int,int>>> q;

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (grid[i][j]) {
                    q.push({i, {j, 0}});
                }
            }
        }

        while (!q.empty()) {
            auto [i, p] = q.front();
            int j = p.first;
            int t = p.second;
            q.pop();
            if (dis[i][j] <= t) continue;
            dis[i][j] = t;
            for (int k = 0; k < 4; ++k) {
                int ii = i + hr[k];
                int jj = j + vr[k];
                if (~ii && ii < r && ~jj && jj < c && dis[ii][jj] > t+1) {
                    q.push({ii, {jj, t+1}});
                }
            }  
        }

        priority_queue<pair<int, pair<int,int>>> pq;
        vector<vector<bool>> vis(r, vector<bool>(c));
        pq.push({dis[0][0], {0, 0}});
        
        while (!pq.empty()) {
            auto[mnE, p] = pq.top();
            int i = p.first;
            int j = p.second;
            pq.pop();
            if (i == r-1 && j == c-1) return mnE;
            if (vis[i][j]) continue;
            vis[i][j] = 1;
            for (int k = 0; k < 4; ++k) {
                int ii = i + hr[k];
                int jj = j + vr[k];
                if (~ii && ii < r && ~jj && jj < c && !vis[ii][jj]) {
                    pq.push({min(mnE, dis[ii][jj]), {ii, jj}});
                }
            }
        }
        return 0;
    }
};