class Solution {
public:

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        array<int, 4> hr{0, 1, 0, -1};
        array<int, 4> vr{-1, 0, 1, 0};

        vector<vector<int>> dis(r, vector<int>(c, 1e9));
        queue<array<int, 3>> q;

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (grid[i][j]) {
                    q.push(array<int, 3>{i, j, 0});
                }
            }
        }

        while (!q.empty()) {
            auto [i, j, t] = q.front();
            q.pop();
            if (dis[i][j] <= t) continue;
            dis[i][j] = t;
            for (int k = 0; k < 4; ++k) {
                int ii = i + hr[k];
                int jj = j + vr[k];
                if (ii >= 0 && ii < r && jj >= 0 && jj < c && dis[ii][jj] > t + 1) {
                    q.push(array<int, 3>{ii, jj, t + 1});
                }
            }
        }

        priority_queue<array<int, 3>> pq;
        vector<vector<bool>> vis(r, vector<bool>(c));

        pq.push(array<int, 3>{dis[0][0], 0, 0});

        while (!pq.empty()) {
            auto [mnE, i, j] = pq.top();
            pq.pop();
            if (i == r - 1 && j == c - 1) return mnE;
            if (vis[i][j]) continue;
            vis[i][j] = true;
            for (int k = 0; k < 4; ++k) {
                int ii = i + hr[k];
                int jj = j + vr[k];
                if (ii >= 0 && ii < r && jj >= 0 && jj < c && !vis[ii][jj]) {
                    pq.push(array<int, 3>{min(mnE, dis[ii][jj]), ii, jj});
                }
            }
        }

        return 0; // unreachable code
    }
};