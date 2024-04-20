class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int rws[4] = {-1,0,1,0};
        int cls[4] = {0,-1,0,1};
        int r = land.size();
        int c = land[0].size();
        vector<vector<int>> ans;
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(r, vector<bool>(c));
        int ct = 0;
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j) {
                if (!vis[i][j] && land[i][j] == 1) {
                    ++ct;
                    vector<int> v;
                    v.push_back(i);
                    v.push_back(j);
                    vis[i][j] = 1;
                    q.push({i,j});
                    while (q.size()) {
                        int rr = q.front().first;
                        int cc = q.front().second;
                        q.pop();
                        for (int i = 0; i < 4; ++i) {
                            int nr = rr + rws[i];
                            int nc = cc + cls[i];
                            if (~nr && nr < r && ~nc && nc < c && land[nr][nc] && !vis[nr][nc]) {
                                q.push({nr, nc});
                                vis[nr][nc] = 1;
                                if ((nr+1 == r || land[nr+1][nc] == 0) && (nc+1 == c || land[nr][nc+1] == 0)) {
                                    v.push_back(nr);
                                    v.push_back(nc);
                                }
                            }
                        }
                    }
                    if (v.size() == 2) {
                        v.push_back(i);
                        v.push_back(j);
                    }
                    ans.push_back(v);
                }
            }
        cout << ct << '\n';
        return ans;
    }
};