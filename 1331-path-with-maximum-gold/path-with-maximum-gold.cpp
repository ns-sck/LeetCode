class Solution {
public:
    int rr[4] = {1,0,-1,0};
    int cc[4] = {0,1,0,-1};
    int r1, c1;
    int dfs (vector<vector<bool>>& act, int i, int j, int t, vector<vector<int>>& grid) {
        int x = t;
        act[i][j] = 1;
        for (int k = 0; k < 4; ++k) {
            int nr = i + rr[k];
            int nc = j + cc[k];
            if (~nc && nc < c1 && ~nr && nr < r1 && !act[nr][nc] && grid[nr][nc]) {
                x = max(x, dfs(act, nr, nc, t+grid[nr][nc], grid));
            }
        }
        act[i][j] = 0;
        return x;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        r1 = r, c1 = c;
        int ans = 0;
        vector<vector<bool>> act(r, vector<bool>(c));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j) {
                if (!grid[i][j]) continue;
                ans = max(ans, dfs(act, i, j, grid[i][j], grid));
            }
        return ans;
    }
};