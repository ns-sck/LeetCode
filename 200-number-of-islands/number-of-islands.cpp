class Solution {
public:
    int rws[4] = {0,-1,0,1};
    int cls[4] = {-1,0,1,0};
    int numIslands(vector<vector<char>>& grid) {
        ios::sync_with_stdio;
        int r = grid.size();
        int c = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(r, vector<bool>(c));
        int ans = 0;
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    ++ans;
                    vis[i][j] = 1;
                    q.push({i,j});
                    while (q.size()) {
                        int rr = q.front().first;
                        int cc = q.front().second;
                        q.pop();
                        for (int i = 0; i < 4; ++i) {
                            int nr = rr + rws[i];
                            int nc = cc + cls[i];
                            if (~nr && nr < r && ~nc && nc < c && !vis[nr][nc] && grid[nr][nc] == '1') {
                                q.push({nr, nc});
                                vis[nr][nc] = 1;
                            }
                        }
                    }
                }
            }
        return ans;
    }
};