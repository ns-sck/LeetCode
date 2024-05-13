class Solution {
public:
    int matrixScore(vector<vector<int>>& g) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n = g.size(), m = g[0].size();
        int ans = (1 << (m - 1)) * n;
        for(int j = 1; j < m; ++j) {
            int v = 1 << (m - 1 - j);
            int s = 0;
            for(int i = 0; i < n; ++i) {
                if(g[i][j] == g[i][0]) {
                    s++;
                }
            }
            ans += max(s, n-s) * v;
        }
        return ans;
    }
};