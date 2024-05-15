class Solution {
public:
    static constexpr int DIRS = 4;
    static constexpr int INF = 1e9;

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        array<int, DIRS> hr{0, 1, 0, -1};
        array<int, DIRS> vr{-1, 0, 1, 0};

        vector<vector<int>> dis(rows, vector<int>(cols, INF));
        queue<array<int, 3>> q;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j]) {
                    q.emplace(array<int, 3>{i, j, 0});
                }
            }
        }

        while (!q.empty()) {
            auto [i, j, t] = q.front();
            q.pop();
            if (dis[i][j] <= t) continue;
            dis[i][j] = t;
            for (int k = 0; k < DIRS; ++k) {
                int ii = i + hr[k];
                int jj = j + vr[k];
                if (ii >= 0 && ii < rows && jj >= 0 && jj < cols && dis[ii][jj] > t + 1) {
                    q.emplace(array<int, 3>{ii, jj, t + 1});
                }
            }
        }

        priority_queue<array<int, 3>> pq;
        vector<vector<bool>> vis(rows, vector<bool>(cols));

        pq.emplace(array<int, 3>{dis[0][0], 0, 0});

        while (!pq.empty()) {
            auto [mnE, i, j] = pq.top();
            pq.pop();
            if (i == rows - 1 && j == cols - 1) return mnE;
            if (vis[i][j]) continue;
            vis[i][j] = true;
            for (int k = 0; k < DIRS; ++k) {
                int ii = i + hr[k];
                int jj = j + vr[k];
                if (ii >= 0 && ii < rows && jj >= 0 && jj < cols && !vis[ii][jj]) {
                    pq.emplace(array<int, 3>{min(mnE, dis[ii][jj]), ii, jj});
                }
            }
        }

        return 0; // unreachable code
    }
};